#include <cstdint>
#include "bitfield.h"

using namespace btf;
typedef bitfield<uint8_t, 3, 5> mybtf;

int main()
{
	printf("size_t is: %zd\n", sizeof(size_t));
	// print_bit_repr<uint8_t>(3);
	// print_bit_repr<uint16_t>(11);
	// print_bit_repr(make_mask<uint8_t>(1, 3));
	// printf("%zd\n", sum_up_to<2, 7, 8, 9>::value);
	mybtf b;
	printf("bitfield is: %zd\n", sizeof(b));
	printf("store: %d\n", b.GetStore());
	b.SetField<0>(2); // 10
	print_bit_repr(b.GetStore());
	b.SetField<0>(4); // 100
	print_bit_repr(b.GetStore());
	b.SetField<0>(6); // 110
	print_bit_repr(b.GetStore());
	b.SetField<0>(15); // 1111
	print_bit_repr(b.GetStore());
	printf("get %d\n", b.GetField<0>());

	b.SetField<1>(15);
	print_bit_repr(b.GetStore());
	printf("get %d\n", b.GetField<1>());
	return 0;
}


