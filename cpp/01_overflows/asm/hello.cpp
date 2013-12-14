#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "overflows.h"

using namespace ovf;


short regular_avg(short a, short b)
{
	return (a + b) / 2;
}

short safe_avg(short a, short b)
{
	return average(a, b);
}

bool add_ovf1(short a, short b)
{
	typedef ::std::numeric_limits<decltype(a)> nl;
	typedef larger_type<decltype(a)>::fast_t lT;
	lT r = lT(a) + lT(b);
	return nl::min() <= r && r <= nl::max();
}

bool add_ovf2(short a, short b)
{
	return addition_overflows(a, b);
}

bool mult_ovf1(short a, short b)
{
	typedef ::std::numeric_limits<decltype(a)> nl;
	typedef larger_type<decltype(a)>::fast_t lT;
	lT r = lT(a) * lT(b);
	return nl::min() <= r && r <= nl::max();
}

bool mult_ovf2(short a, short b)
{
	return multiplication_overflows(a, b);
}
