
ifeq ($F,0)
o = -O0
else
o = -O2
endif

.PHONY: all
all:
	g++ -S -fverbose-asm $o -std=c++11 hello.cpp -o out.s
	vim out.s
