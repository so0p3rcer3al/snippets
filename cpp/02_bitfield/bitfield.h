/*
 * Efficient bitfield implementation that uses an unsigned
 * int as the underlying representation.
 * The generated bytecode is identical to that of the builtin
 * bitfield when compiled using gcc 4.8.1 and clang 3.4. An
 * advantage of this implementation is that the total size is
 * guaranteed. While a disadvantage is that it's arguably
 * harder to use because fields cannot be labeled/named.
 * Nov 27 2013
 */
#ifndef BITFIELDS_H
#define BITFIELDS_H

#include <limits>
#include <type_traits>
#include <cstdio> /* note: also includes def'n for size_t */
namespace btf {


template <typename U>
static void print_bit_repr(U n)
{
	static_assert(::std::is_unsigned<U>::value, "U must be unsigned");
	typedef ::std::numeric_limits<U> nl;
	printf("\n");
	for (int i = nl::digits - 1; i >= 0; --i)
		printf("%2d ", i);
	printf(" <- 2^i\n");
	for (int i = nl::digits - 1; i >= 0; --i)
		printf("%2d ", (n & (1u << i)) != 0);
	printf("\n");
}





/*
 * The first template parameter is the underlying type, followed
 * by the desired partitioning scheme.
 * E.g., bitfield<uint8_t, 2,2,3,1> myBitfield;
 * For alignment purposes, 0 is an allowable width. Although
 * any attempts at setting or getting 0 width fields will
 * result in a compile time error.
 */
template <typename U, size_t... widths>
class bitfield {
private:
	/* helpers */

	/*
	 * For a sequence [a,b,c,..], calculates the sum of the
	 * subsequence from [0,i).
	 */
	template <size_t i, size_t a, size_t... bcd>
	struct sum_up_to {
		static constexpr size_t value = i > 0 ?
			a + sum_up_to<i-1, bcd...>::value : 0;
	};
	template <size_t i, size_t a>
	struct sum_up_to<i, a> {
		static constexpr size_t value = i > 0 ?
			a : 0;
	};

	/*
	 * For a sequence A = [a,b,c,..], gets the value of A[i].
	 * (Or the last element, if i is out of range.)
	 */
	template <size_t i, size_t a, size_t... bcd>
	struct value_at {
		static constexpr size_t value = i > 0 ?
			value_at<i-1, bcd...>::value : a;
	};
	template <size_t i, size_t a>
	struct value_at<i, a> {
		static constexpr size_t value = a;
	};

	typedef ::std::numeric_limits<U> nl;
	static constexpr size_t field_count = sizeof...(widths);
	static constexpr size_t total_width = sum_up_to<field_count, widths...>::value;
	static_assert(::std::is_unsigned<U>::value, "U must be unsigned");
	static_assert(total_width <= nl::digits, "U is not large enough");
	static_assert(total_width == nl::digits, "(WARN) not all bits are used");

	/*
	 * Contains information on the i-th field.
	 * mask= ..0000111100 <- least significant bit
	 *                ^ offset=2, width=4
	 */
	template <size_t i>
	struct field_info {
		static constexpr size_t offset = sum_up_to<i, widths...>::value;
		static constexpr size_t width  = value_at<i, widths...>::value;
		static constexpr size_t mask   = U(nl::max() >> (nl::digits - width) << offset);
	};
private:
	U store = 0;
public:

	U GetStore()
	{
		return store;
	}

	void SetStore(U n)
	{
		store = n;
	}

	template <size_t i>
	U GetField()
	{
		typedef field_info<i> fi;
		/* size_t is unsigned so i <= 0 is a given. */
		static_assert(i < field_count, "i is out of bounds");
		static_assert(fi::width > 0, "field has no data");

		/* "Cut out" the desired bits. */
		return (store & fi::mask) >> fi::offset;
	}

	template <size_t i>
	void SetField(U n)
	{
		typedef field_info<i> fi;
		static_assert(i < field_count, "i is out of bounds");
		/* Can also just ignore the value. */
		static_assert(fi::width > 0, "field has no data");

		/* Shift n into its correct position.
		 * & fi::mask ensures that oversize values will not
		 * overwrite the contents of adjacent fields. */
		n = U(n << fi::offset)/* & fi::mask */;
		/* Zero out the previous value and combine. */
		store = U((store & ~fi::mask) | n);
	}

	template <size_t i>
	constexpr U FieldMax()
	{
		typedef field_info<i> fi;
		static_assert(i < field_count, "i is out of bounds");
		static_assert(fi::width > 0, "field has no data");

		return fi::mask >> fi::offset;
	}
};


} /* namespace btf */
#endif/* BITFIELDS_H */

