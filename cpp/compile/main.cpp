#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <typeinfo>
#include "overflows.h"

typedef short T;
typedef long  U;

using namespace ovf;

int main()
{
	addition_overflows<T>(0, 0);
	addition_overflows<U>(0, 0);

	average<T>(0, 0);
	average<U>(0, 0);

	printf("5 -> %u\n", to_unsigned((signed char)5));
	printf("-5 -> %u\n", to_unsigned(-5));

	printf("5 -> %d\n", to_signed((unsigned char)5));
	printf("4294967291 -> %d\n", to_signed(4294967291u));
	printf("4294967291 ?> %d\n", (int)4294967291u);

	typedef larger_type<char> flt;
	printf("%d -> %d\n", flt::is_available,
		::std::is_same<flt::fast_t, long>::value);

	printf("%d %d -> %d\n", 3, 4, average<T>(3, 4));
	return 0;
}


