
cxx = g++
o   = -O2
# need for icpc
misc = -I/usr/include/x86_64-linux-gnu/c++/4.8

.PHONY: all
all:
	$(cxx) -S -fverbose-asm $(misc) $o -std=c++11 hello.cpp -o $(cxx).s
	vim $(cxx).s


