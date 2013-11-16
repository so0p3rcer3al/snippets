/*
 * Utilities for detecting and avoiding overflows.
 */
#ifndef OVERFLOWS_H
#define OVERFLOWS_H

#include <limits>
#include <type_traits>
#include <cstdint>

#pragma GCC diagnostic push
/*
 * Do not warn about checking n >= 0 when T is unsigned.
 * (has been fixed in gcc 4.8, though)
 */
// #pragma GCC diagnostic ignored "-Wtype-limits"
namespace ovf {


/*
 * Returns true if op will overflow, false otherwise.
 */
template <typename T> bool addition_overflows       (T a, T b);
template <typename T> bool subtraction_overflows    (T a, T b);
template <typename T> bool multiplication_overflows (T a, T b);
template <typename T> bool division_overflows       (T a, T b);
template <typename T> bool modulo_overflows         (T a, T b);


/*
 * Converts signed -> unsigned without overflow.
 * If the value is negative, T_MIN+1 is added to bump it into range
 * (this is well-defined behavior).
 */
template <typename S, typename U = typename ::std::make_unsigned<S>::type>
U to_unsigned(S n);
/*
 * Converts unsigned -> signed without overflow
 * such that it "reverses" the transformation from signed -> unsigned.
 */
template <typename U, typename S = typename ::std::make_signed<U>::type>
S to_signed(U n);


/*
 * Has fields <is_available>, <fast_t>, and <least_t>.
 * The types are valid only when <is_available> is true.
 */
template <typename T>
class larger_type;


/*
 * Equivalent to (a+b)/2, but will not cause an intermediate overflow.
 */
template <typename T>
T average(T a, T b);





/*
 *         For overflow checking,
 *
 * In general, we want to check for some operation that
 * T_MIN <= a OP b <= T_MAX without breaking the limits in the
 * process.
 *
 * The current approach splits each operation into cases based
 * on the signs of a and b. For each case, we find statements
 * that are guaranteed to be safe and use those to deduce the
 * answer.
 *
 * Another (more popular) method is to perform the operation
 * using a larger datatype and check the result afterwards. If
 * the initial type is already very large, then a custom,
 * environment/architecture/problem-specific solution is probably
 * appropriate.
 *
 * Note that unsigned types technically do not overflow. They
 * are defined by c/c++ standards to wrap around from
 * T_MIN <-> T_MAX. Signed overflow, on the other hand, is
 * undefined. The compiler is free to do whatever it wants when
 * that happens, which gcc often does on -O2 or -O3!
 */

/*
 * We want to check that a+b <= T_MAX, and similarly for T_MIN.
 * This is equivalent to checking a <= T_MAX-b. When b >= 0,
 * T_MAX-b cannot underflow. So we simply compute our answer.
 */
template <typename T>
extern inline bool addition_overflows(T a, T b)
{
	typedef ::std::numeric_limits<T> tl;
	static_assert(tl::is_integer, "T must be integral type");
	constexpr bool u = !tl::is_signed;

	if (b >= 0 || u)
		return a > (tl::max() - b);
	return a < (tl::min() - b);
}

/*
 * Similar approach as addition, but with a flipped b.
 *
 * This is NOT equivalent to return addition_overflows<T>(a, -b).
 * The negation on b will cause an overflow when b is T_MIN.
 */
template <typename T>
extern inline bool subtraction_overflows(T a, T b)
{
	typedef ::std::numeric_limits<T> tl;
	static_assert(tl::is_integer, "T must be integral type");
	constexpr bool u = !tl::is_signed;

	if (b >= 0 || u)
		return a < (tl::min() + b);
	return a > (tl::max() + b);
}

/*
 * Multiplication is a bit trickier since the signs of a and b
 * together determine whether the op may overflow or underflow.
 * We also have to make sure we do not divide T_MIN by -1 since
 * that causes divison overflow.
 */
template <typename T>
extern inline bool multiplication_overflows(T a, T b)
{
	typedef ::std::numeric_limits<T> tl;
	static_assert(tl::is_integer, "T must be integral type");
	constexpr bool u = !tl::is_signed;

	if (u)
		return (b != 0) && a > (tl::max() / b);

	if (a > 0) {
		if (b > 0)
			return b > (tl::max() / a);
		return b < (tl::min() / a);
	} else {
		if (b > 0)
			return a < (tl::min() / b);
		return (b != 0) && a < (tl::max() / b);
	}
}

/*
 * Int division can't make a number bigger (magnitude). But the
 * resulting sign could be positive or negative. The only
 * negative number that doesn't have a positive equivalent is
 * T_MIN, so we check for that.
 *
 * While we're at it, check for division by zero, too.
 */
template <typename T>
extern inline bool division_overflows(T a, T b)
{
	typedef ::std::numeric_limits<T> tl;
	static_assert(tl::is_integer, "T must be integral type");
	constexpr bool u = !tl::is_signed;

	if (b == 0)
		return true;
	if (u)
		return false;
	return (a == tl::min()) && (b == -1);
}

/*
 * In most specifications (e.g., c++11), modulo is defined such
 * that (a/b)*b + a%b == a. And when a/b cannot be properly
 * represented (when a = T_MIN, b = -1), modulo is undefined.
 *
 * Another viable but brow-raising alternative is to
 * extrapolate how the edge case is handled by evaluating
 * (signed char)(-128 % -1) == 0 at compile time.
 *
 * Mod by 0 is not allowed either. So check for that.
 */
template <typename T>
extern inline bool modulo_overflows(T a, T b)
{
	typedef ::std::numeric_limits<T> tl;
	static_assert(tl::is_integer, "T must be integral type");
	constexpr bool u = !tl::is_signed;

	/* completely identical to checking division */
	if (b == 0)
		return true;
	if (u)
		return false;
	return (a == tl::min()) && (b == -1);
}





/*
 * Signed -> unsigned conversion is well-defined.
 * Negative values are incremented by UNSIGNED_MAX+1 to bump
 * them into range while positive ones are converted directly.
 */
template <typename S, typename U>
extern inline U to_unsigned(S n)
{
	typedef ::std::numeric_limits<S> sl;
	static_assert(sl::is_signed, "S must be signed");
	/* TODO: check validity if non-default U.
	 * (default U already creates error if S does not have an
	 * unsigned equivalent -- i.e., is not an int.) */
	return U(n);
}

/*
 * Unsigned -> signed conversion is only well-defined when no
 * overflow occurs. We can avoid this by subtracting the (unsigned
 * equivalent of) SIGNED_MIN and then adding it back after
 * conversionn, if necessary.
 */
template <typename U, typename S>
extern inline S to_signed(U n)
{
	typedef ::std::numeric_limits<U> ul;
	typedef ::std::numeric_limits<S> sl;
	static_assert(!ul::is_signed, "U must be unsigned");
	/* TODO: check validity if non-default S */
	static_assert(U(sl::max()) + 1 == U(sl::min()),
		"Signed type does not wrap. So this algorithm is inapplicable");

	if (n <= U(sl::max()))
		return S(n);
	/* n > sl::max() -- i.e., n >= sl::min() */
	return S(S(n - U(sl::min())) + sl::min());
}





/*
 * Provides a convenient way of obtaining a larger type when using
 * templates, which can be used to store intermediate calculations
 * and avoid overflow.
 *
 * This does not create a compile error if no larger types are
 * available, allowing the programmer to implement a fallback
 * solution. But note that even in this case, the types will be
 * void and thus unusable.
 */
template <typename T>
class larger_type {
private:
	/* helpers to improve readability. also offers convenient way
	 * to tweak behavior. */
	typedef ::std::numeric_limits<T> tl;
	static_assert(tl::is_integer, "T must be integral type");
	static constexpr size_t current = sizeof(T);
	static constexpr size_t desired = current * 2;

	template <typename A>
	struct is_ok {
		static constexpr bool value = sizeof(A) >= desired;
	};

	/* considers each type in order and selects the first one
	 * that meets our criteria */
	template <typename A, typename... BCD>
	struct consider_in_order {
		/* take current type or recursively move on to next */
		typedef typename ::std::conditional<is_ok<A>::value,
			A, typename consider_in_order<BCD...>::type
			>::type type;
	};
	/* special case: only one remaining option */
	template <typename A>
	struct consider_in_order<A> {
		typedef typename ::std::conditional<is_ok<A>::value,
			A, void
			>::type type;
	};
public:
	/* only meaningful if <is_available> is true. */
	typedef typename ::std::conditional<tl::is_signed,
		typename consider_in_order<
			int_fast8_t, int_fast16_t,
			int_fast32_t, int_fast64_t>::type,
		typename consider_in_order<
			uint_fast8_t, uint_fast16_t,
			uint_fast32_t, uint_fast64_t>::type
		>::type fast_t;

	/* only meaningful if <is_available> is true. */
	typedef typename ::std::conditional<tl::is_signed,
		typename consider_in_order<
			int_least8_t, int_least16_t,
			int_least32_t, int_least64_t>::type,
		typename consider_in_order<
			uint_least8_t, uint_least16_t,
			uint_least32_t, uint_least64_t>::type
		>::type least_t;

	/* true only if <least_t> and <fast_t> are valid and usable. */
	static constexpr bool is_available = tl::is_integer &&
				!::std::is_same<fast_t, void>::value &&
				!::std::is_same<least_t, void>::value;
};





/*
 * Returns the average of the two parameters. The final result is guaranteed
 * to be representable as type T, but the classic method (a+b)/2 risks
 * an intermediate overflow.
 * (This was actually the cause of a bug in Java's binarySearch that
 *  had gone unnoticed for almost a decade!)
 *
 *  The best solution for signed types might be to store the sum
 *  in a larger intermediate type and cast it back afterwards.
 *  Note that popular suggestions such as a/2 + b/2 + (a%2 + b%2)/2
 *  fail for cases such as -2,1 (expected 0).
 */
template <typename T>
extern inline T average(T a, T b)
{
	typedef ::std::numeric_limits<T> tl;
	static_assert(tl::is_integer, "T must be integral type");
	constexpr bool u = !tl::is_signed;
	/* should probably just suppress the stupid -Wconversion warning
	 * instead of casting everything ... */

	if (u)
		return T((a / 2) + (b / 2) + (a & b & 1));

	/* work in progress -- terribly inefficient ATM. */
	if ((a > 0) == (b > 0)) {
		T x  = a / 2;
		T y  = b / 2;
		/* GCC doesn't optimize n % 2 properly.
		 * and the standard promises that (a/b)*b + a%b == a. */
		T md = T((a - x * 2) + (b - y * 2));
		return T(x + y + (md / 2));
	} else {
		return T((a + b) / 2);
	}
}





} /* namespace ovf */
#pragma GCC diagnostic pop
#endif/* OVERFLOWS_H */

