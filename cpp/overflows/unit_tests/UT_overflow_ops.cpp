#include <gtest/gtest.h>
#include <stdio.h>
#include <limits.h>
#include "overflows.h"

using namespace ovf;

template <typename T>
class UT_overflow_ops : public ::testing::Test {
public:
	typedef ::std::numeric_limits<T> nl;
	typedef T (*ovfunc)(T a, T b);

	void CheckAll(ovfunc actual, ovfunc tested)
	{
		long cycles = 0, fails  = 0;
		for (long _a = nl::min(); _a <= nl::max(); ++_a) {
		for (long _b = nl::min(); _b <= nl::max(); ++_b) {
			T a = _a, b = _b;
			++cycles;
			T r1 = actual(a, b);
			T r2 = tested(a, b);
			if (r1 != r2) {
				printf("case: %d %d, ", a, b);
				printf("expected %d, func %d\n", r1, r2);
				++fails;
				if (fails >= 5)
					FAIL() << "too many fails";
			}
		}
		}
		long N = nl::max() - nl::min() + 1;
		ASSERT_EQ(N * N, cycles);
	}
};

typedef ::testing::Types<signed char, unsigned char> TestTypes;
TYPED_TEST_CASE(UT_overflow_ops, TestTypes);

TYPED_TEST(UT_overflow_ops, Average)
{
	this->CheckAll([](TypeParam a, TypeParam b) {
		long r = ((long)a + (long)b)/2L;
		return (TypeParam)r;
	}, average<TypeParam>);
}

