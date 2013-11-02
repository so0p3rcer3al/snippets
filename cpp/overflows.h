/*
 * Contains utilities for overflow checking.
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
 * the initial type is already very large, the result can be
 * approximated using floating points, and possibly adjusted so
 * that no false negatives will be given.
 *
 * Note that unsigned types technically do not overflow. They
 * are defined by c/c++ standards to wrap around from
 * T_MIN <-> T_MAX. Signed overflow, on the other hand, is
 * undefined. The compiler is free to do whatever it wants when
 * that happens, which gcc often does on -O2 or -O3!
 *
 */
#ifndef OVERFLOWS_H
#define OVERFLOWS_H

#include <limits>
/*
 * Do not warn about redundant checks.
 * In particular, about n >= 0 when T is an unsigned type.
 */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"




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
 */
template <typename T>
extern inline bool multiplication_overflows(T a, T b)
{
	typedef ::std::numeric_limits<T> tl;
	static_assert(tl::is_integer, "T must be integral type");
	constexpr bool u = !tl::is_signed;

	if (a >= 0 || u) {
		if (b >= 0 || u)
			return (b > 0) && a > (tl::max() / b);
		return a > (tl::min() / b);
	} else {
		if (b >= 0)
			return (b > 0) && a < (tl::min() / b);
		return a < (tl::max() / b);
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




#pragma GCC diagnostic pop
#endif/* OVERFLOWS_H */

