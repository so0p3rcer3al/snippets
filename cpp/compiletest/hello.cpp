#include <stdio.h>
#include <stdlib.h>
#include "overflows.h"

int main(void)
{
	bool r1 = addition_overflows<unsigned int>(1, 3);
	bool r2 = subtraction_overflows<unsigned int>(1, 3);
	bool r3 = multiplication_overflows<unsigned int>(1, 3);
	bool r4 = division_overflows<unsigned int>(1, 3);
	bool r5 = modulo_overflows<unsigned int>(1, 3);
	// check that GCC pragmas get disabled
	unsigned int a = 2;
	if (a >= 0) {
		puts("well duh");
	}
	printf("%d\n", r1);
	return 0;
}

