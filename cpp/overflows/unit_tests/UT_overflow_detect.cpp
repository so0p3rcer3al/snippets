#include <gtest/gtest.h>
#include <stdio.h>
#include <limits.h>
#include "overflows.h"

using namespace ovf;

template <typename T>
class UT_overflow_detect : public ::testing::Test {
public:
	typedef ::std::numeric_limits<T> nl;
	typedef bool (*ovfunc)(T a, T b);

	void CheckAll(ovfunc actual, ovfunc tested)
	{
		long cycles = 0, fails  = 0;
		for (long _a = nl::min(); _a <= nl::max(); ++_a) {
			T a = _a;
			for (long _b = nl::min(); _b <= nl::max(); ++_b) {
				T b = _b;
				++cycles;
				bool r1 = actual(a, b);
				bool r2 = tested(a, b);
				if (r1 != r2) {
					++fails;
					printf("fail on %d, %d. ans is %d\n",
							a, b, r1);
					if (fails >= 5)
						FAIL() << "too many fails";
				}
			}
		}
		long N = nl::max() - nl::min() + 1;
		ASSERT_EQ(N * N, cycles);
	}
};

typedef ::testing::Types<int8_t, uint8_t, int16_t, uint16_t> TestTypes;
TYPED_TEST_CASE(UT_overflow_detect, TestTypes);

TYPED_TEST(UT_overflow_detect, Addition)
{
	this->CheckAll([](TypeParam a, TypeParam b) {
		typedef ::std::numeric_limits<TypeParam> nl;
		long r = (long)a + (long)b;
		return !(nl::min() <= r && r <= nl::max());
	}, addition_overflows<TypeParam>);
}

TYPED_TEST(UT_overflow_detect, Subtraction)
{
	this->CheckAll([](TypeParam a, TypeParam b) {
		typedef ::std::numeric_limits<TypeParam> nl;
		long r = (long)a - (long)b;
		return !(nl::min() <= r && r <= nl::max());
	}, subtraction_overflows<TypeParam>);
}

TYPED_TEST(UT_overflow_detect, Multiplication)
{
	this->CheckAll([](TypeParam a, TypeParam b) {
		typedef ::std::numeric_limits<TypeParam> nl;
		long r = (long)a * (long)b;
		return !(nl::min() <= r && r <= nl::max());
	}, multiplication_overflows<TypeParam>);
}

TYPED_TEST(UT_overflow_detect, Division)
{
	this->CheckAll([](TypeParam a, TypeParam b) {
		typedef ::std::numeric_limits<TypeParam> nl;
		if (b == 0) return true;
		long r = (long)a / (long)b;
		return !(nl::min() <= r && r <= nl::max());
	}, division_overflows<TypeParam>);
}

TYPED_TEST(UT_overflow_detect, Modulo)
{
	this->CheckAll([](TypeParam a, TypeParam b) {
		typedef ::std::numeric_limits<TypeParam> nl;
		if (b == 0) return true;
		long r = (long)a % (long)b;
		return !(nl::min() <= r && r <= nl::max());
	}, modulo_overflows<TypeParam>);
}
