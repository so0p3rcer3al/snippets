#include <gtest/gtest.h>
#include <stdio.h>
#include "overflows.h"

#include <string>
#include <cstdint>

using namespace ovf;
using ::std::is_same;

TEST(UT_overflow_largertype, Invalid)
{
	/* updated -- will now cause compile error */
	// ASSERT_FALSE(larger_type<float>::is_available);
	// ASSERT_FALSE(larger_type<double>::is_available);
	// ASSERT_FALSE(larger_type<::std::string>::is_available);
}

#define fast_tcomp(FROM, TO) \
	printf("sizeof %zd -> %zd\n", sizeof(FROM), sizeof(larger_type<FROM>::fast_t)); \
	ASSERT_TRUE((is_same<larger_type<FROM>::fast_t, TO>::value)); \
	ASSERT_TRUE(larger_type<FROM>::is_available);

#define least_tcomp(FROM, TO) \
	printf("sizeof %zd -> %zd\n", sizeof(FROM), sizeof(larger_type<FROM>::least_t)); \
	ASSERT_TRUE((is_same<larger_type<FROM>::least_t, TO>::value)); \
	ASSERT_TRUE(larger_type<FROM>::is_available);

TEST(UT_overflow_largertype, Fast)
{
	fast_tcomp(int8_t, int_fast16_t);
	fast_tcomp(int16_t, int_fast32_t);
	fast_tcomp(int32_t, int_fast64_t);
	ASSERT_FALSE(larger_type<int64_t>::is_available);

	fast_tcomp(uint8_t, uint_fast16_t);
	fast_tcomp(uint16_t, uint_fast32_t);
	fast_tcomp(uint32_t, uint_fast64_t);
	ASSERT_FALSE(larger_type<uint64_t>::is_available);
}

TEST(UT_overflow_largertype, Least)
{
	least_tcomp(int8_t, int_least16_t);
	least_tcomp(int16_t, int_least32_t);
	least_tcomp(int32_t, int_least64_t);
	ASSERT_FALSE(larger_type<int64_t>::is_available);

	least_tcomp(uint8_t, uint_least16_t);
	least_tcomp(uint16_t, uint_least32_t);
	least_tcomp(uint32_t, uint_least64_t);
	ASSERT_FALSE(larger_type<uint64_t>::is_available);
}
