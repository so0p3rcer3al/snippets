#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "bitfield.h"

using namespace btf;

/*
 * Goal:  Check that the templated version produces similar
 *        (or better) asm as the built-in.
 */
bitfield<uint8_t, 7, 1> bf;
struct {
	uint8_t a : 7;
	uint8_t b : 1;
} bf_R;
static_assert(sizeof(bf)   == sizeof(uint8_t), "");
static_assert(sizeof(bf_R) == sizeof(uint8_t), "");


/*
 * g++4.8.1      identical
 * clang++3.4    identical
 */
uint8_t get_field0_comp()
{
	return bf_R.a;
}
uint8_t get_field0_orig()
{
	return bf.GetField<0>();
}


/*
 * g++4.8.1      identical
 * clang++3.4    identical
 */
uint8_t get_field1_comp()
{
	return bf_R.b;
}
uint8_t get_field1_orig()
{
	return bf.GetField<1>();
}


/*
 * g++4.8.1      effectively identical
 *               (but _comp cuts off extra bits for oversize values)
 * clang++3.4    same as g++
 */
void set_field0_comp(uint8_t n)
{
	bf_R.a = n;
}
void set_field0_orig(uint8_t n)
{
	bf.SetField<0>(n);
}


/*
 * g++4.8.1      identical
 * clang++3.4    identical
 */
void set_field1_comp(uint8_t n)
{
	bf_R.b = n;
}
void set_field1_orig(uint8_t n)
{
	bf.SetField<1>(n);
}

