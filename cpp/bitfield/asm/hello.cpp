#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "bitfield.h"

using namespace btf;

/*
 * Goal: check that the templated version produces identical
 * asm as the expected/optimal version.
 */
bitfield<uint8_t, 7, 1> bf;


/*
 * g++      OK
 * clang++  OK
 * icpc     OK
 */
uint8_t get_field0_comp()
{
	/* 0111 1111 -> 0x7F */
	uint8_t store = bf.GetStore();
	return 0x7F & store;
}
uint8_t get_field0_orig()
{
	return bf.GetField<0>();
}


/*
 * g++      OK
 * clang++  OK
 * icpc     OK
 */
uint8_t get_field1_comp()
{
	/* 1000 0000 -> 0x80 */
	uint8_t store = bf.GetStore();
	return (0x80 & store) >> 7u;
}
uint8_t get_field1_orig()
{
	return bf.GetField<1>();
}


/*
 * g++      OK
 * clang++  OK
 * icpc     OK
 */
void set_field0_comp(uint8_t n)
{
	/* 1000 0000 -> 0x80 */
	uint8_t store = bf.GetStore();
	bf.SetStore((store & 0x80) | n);
}
void set_field0_orig(uint8_t n)
{
	bf.SetField<0>(n);
}


void set_field1_comp(uint8_t n)
{
	/* 0111 1111 -> 0x7F */
	uint8_t store = bf.GetStore();
	bf.SetStore((store & 0x7F) | (n << 7u));
}
void set_field1_orig(uint8_t n)
{
	bf.SetField<1>(n);
}

