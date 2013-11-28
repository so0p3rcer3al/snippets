#include <cstdio>
#include <limits>
#include <random>
#include "gtest/gtest.h"
#include "bitfield.h"

using namespace btf;

/*
 * We'll be using unsigned as an intermediate type so that we
 * can (possibly) iterate over the entire range of allowable
 * values for uint8_t.
 */
static_assert(sizeof(unsigned) > sizeof(uint8_t), "your system is screwed up");

/*
 * 8 bytes divided into 3-5.
 */
TEST(UT_fieldsetting, StandardSplit)
{
	bitfield<uint8_t, 3,5> bf;
	ASSERT_EQ((1u << 3)-1u, bf.FieldMax<0>());
	ASSERT_EQ((1u << 5)-1u, bf.FieldMax<1>());

	for (unsigned a = 0; a < bf.FieldMax<0>(); ++a)
	for (unsigned b = 0; b < bf.FieldMax<1>(); ++b) {
		uint8_t a0 = bf.GetField<0>();
		uint8_t b0 = bf.GetField<1>();

		bf.SetField<0>(a);
		ASSERT_EQ(a,  bf.GetField<0>());
		ASSERT_EQ(b0, bf.GetField<1>());

		bf.SetField<0>(a0);
		ASSERT_EQ(a0, bf.GetField<0>());
		ASSERT_EQ(b0, bf.GetField<1>());

		bf.SetField<1>(b);
		ASSERT_EQ(a0, bf.GetField<0>());
		ASSERT_EQ(b,  bf.GetField<1>());

		bf.SetField<1>(b0);
		ASSERT_EQ(a0, bf.GetField<0>());
		ASSERT_EQ(b0, bf.GetField<1>());
	}
}


/*
 * Single field occupying entire type.
 */
TEST(UT_fieldsetting, FullWidth)
{
	bitfield<uint8_t, 8> bf;
	typedef ::std::numeric_limits<uint8_t> nl;
	ASSERT_EQ(nl::max(), bf.FieldMax<0>());

	for (unsigned a = 0; a <= nl::max(); ++a) {
		bf.SetField<0>(a);
		ASSERT_EQ(a, bf.GetField<0>());
	}
}


/*
 * Similar to the StandardSplit test where we had the 3-5 split,
 * except this time we have additional empty fields.
 */
TEST(UT_fieldsetting, ZeroPadded)
{
	/*                0 1 2 3 4 5 6 7 */
	bitfield<uint8_t, 0,0,0,0,3,0,5,0> bf;
	ASSERT_EQ((1u << 3)-1u, bf.FieldMax<4>());
	ASSERT_EQ((1u << 5)-1u, bf.FieldMax<6>());

	for (unsigned a = 0; a < bf.FieldMax<4>(); ++a)
	for (unsigned b = 0; b < bf.FieldMax<6>(); ++b) {
		uint8_t a0 = bf.GetField<4>();
		uint8_t b0 = bf.GetField<6>();

		bf.SetField<4>(a);
		ASSERT_EQ(a,  bf.GetField<4>());
		ASSERT_EQ(b0, bf.GetField<6>());

		bf.SetField<4>(a0);
		ASSERT_EQ(a0, bf.GetField<4>());
		ASSERT_EQ(b0, bf.GetField<6>());

		bf.SetField<6>(b);
		ASSERT_EQ(a0, bf.GetField<4>());
		ASSERT_EQ(b,  bf.GetField<6>());

		bf.SetField<6>(b0);
		ASSERT_EQ(a0, bf.GetField<4>());
		ASSERT_EQ(b0, bf.GetField<6>());
	}
}


/*
 * This time, we'll use randomless to help us test any unforseen
 * corner cases.
 */
TEST(UT_fieldsetting, SingleBitFields)
{
	::std::random_device rd;
	::std::mt19937 r(rd());
	::std::uniform_int_distribution<> idxd(0,4),
					v1(0,1), v2(0,3), v3(0,7);

	/*                0 1 2 3 4 */
	bitfield<uint8_t, 1,3,2,1,1> b;

	/* use two loops so that we can have a progress indicator. */
	for (int i = 10; i > 0; --i) {
	for (int k = 0; k < 10*1000*1000; ++k) {
		/* pick the index to insert into */
		size_t  idx = idxd(r);

		/* store current values. we want to make sure
		 * that only our target index gets changed. */
		uint8_t p0 = b.GetField<0>(), p1 = b.GetField<1>(),
			p2 = b.GetField<2>(), p3 = b.GetField<3>(),
			p4 = b.GetField<4>();

		/* set our field */
		uint8_t val;
		switch (idx) {
		case 0:
			/* different indices have different ranges of
			 * allowable values. */
			val = v1(r);
			b.SetField<0>(val);
			ASSERT_EQ(val, b.GetField<0>());
			break;
		case 1:
			val = v3(r);
			b.SetField<1>(val);
			ASSERT_EQ(val, b.GetField<1>());
			break;
		case 2:
			val = v2(r);
			b.SetField<2>(val);
			ASSERT_EQ(val, b.GetField<2>());
			break;
		case 3:
			val = v1(r);
			b.SetField<3>(val);
			ASSERT_EQ(val, b.GetField<3>());
			break;
		case 4:
			val = v1(r);
			b.SetField<4>(val);
			ASSERT_EQ(val, b.GetField<4>());
			break;
		}

		/* check all other fields */
		if (idx != 0) ASSERT_EQ(p0, b.GetField<0>());
		if (idx != 1) ASSERT_EQ(p1, b.GetField<1>());
		if (idx != 2) ASSERT_EQ(p2, b.GetField<2>());
		if (idx != 3) ASSERT_EQ(p3, b.GetField<3>());
		if (idx != 4) ASSERT_EQ(p4, b.GetField<4>());
	}
	printf("%d ", i);
	}
	printf("\n");
}

