	.file	"hello.cpp"
# GNU C++ (Ubuntu/Linaro 4.8.1-10ubuntu8) version 4.8.1 (x86_64-linux-gnu)
#	compiled by GNU C version 4.8.1, GMP version 5.1.2, MPFR version 3.1.1-p2, MPC version 1.0.1
# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -I /usr/include/x86_64-linux-gnu/c++/4.8
# -imultiarch x86_64-linux-gnu -D_GNU_SOURCE hello.cpp -mtune=generic
# -march=x86-64 -auxbase-strip g++.s -O2 -std=c++11 -fverbose-asm
# -fstack-protector -Wformat -Wformat-security
# options enabled:  -faggressive-loop-optimizations
# -fasynchronous-unwind-tables -fauto-inc-dec -fbranch-count-reg
# -fcaller-saves -fcombine-stack-adjustments -fcommon -fcompare-elim
# -fcprop-registers -fcrossjumping -fcse-follow-jumps -fdefer-pop
# -fdelete-null-pointer-checks -fdevirtualize -fdwarf2-cfi-asm
# -fearly-inlining -feliminate-unused-debug-types -fexceptions
# -fexpensive-optimizations -fforward-propagate -ffunction-cse -fgcse
# -fgcse-lm -fgnu-runtime -fguess-branch-probability -fhoist-adjacent-loads
# -fident -fif-conversion -fif-conversion2 -findirect-inlining -finline
# -finline-atomics -finline-functions-called-once -finline-small-functions
# -fipa-cp -fipa-profile -fipa-pure-const -fipa-reference -fipa-sra
# -fira-hoist-pressure -fira-share-save-slots -fira-share-spill-slots
# -fivopts -fkeep-static-consts -fleading-underscore -fmath-errno
# -fmerge-constants -fmerge-debug-strings -fmove-loop-invariants
# -fomit-frame-pointer -foptimize-register-move -foptimize-sibling-calls
# -foptimize-strlen -fpartial-inlining -fpeephole -fpeephole2
# -fprefetch-loop-arrays -free -freg-struct-return -fregmove
# -freorder-blocks -freorder-functions -frerun-cse-after-loop
# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
# -fsched-stalled-insns-dep -fschedule-insns2 -fshow-column -fshrink-wrap
# -fsigned-zeros -fsplit-ivs-in-unroller -fsplit-wide-types
# -fstack-protector -fstrict-aliasing -fstrict-overflow
# -fstrict-volatile-bitfields -fsync-libcalls -fthread-jumps
# -ftoplevel-reorder -ftrapping-math -ftree-bit-ccp -ftree-builtin-call-dce
# -ftree-ccp -ftree-ch -ftree-coalesce-vars -ftree-copy-prop
# -ftree-copyrename -ftree-cselim -ftree-dce -ftree-dominator-opts
# -ftree-dse -ftree-forwprop -ftree-fre -ftree-loop-if-convert
# -ftree-loop-im -ftree-loop-ivcanon -ftree-loop-optimize
# -ftree-parallelize-loops= -ftree-phiprop -ftree-pre -ftree-pta
# -ftree-reassoc -ftree-scev-cprop -ftree-sink -ftree-slp-vectorize
# -ftree-slsr -ftree-sra -ftree-switch-conversion -ftree-tail-merge
# -ftree-ter -ftree-vect-loop-version -ftree-vrp -funit-at-a-time
# -funwind-tables -fverbose-asm -fzero-initialized-in-bss
# -m128bit-long-double -m64 -m80387 -maccumulate-outgoing-args
# -malign-stringops -mfancy-math-387 -mfp-ret-in-387 -mfxsr -mglibc
# -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone -msse
# -msse2 -mtls-direct-seg-refs

	.text
	.p2align 4,,15
	.globl	_Z11regular_avgss
	.type	_Z11regular_avgss, @function
_Z11regular_avgss:
.LFB1444:
	.cfi_startproc
	movswl	%di, %eax	# a, D.32545
	movswl	%si, %esi	# b, D.32545
	addl	%esi, %eax	# D.32545, D.32545
	movl	%eax, %edx	# D.32545, tmp74
	shrl	$31, %edx	#, tmp74
	addl	%edx, %eax	# tmp74, D.32545
	sarl	%eax	# D.32545
	ret
	.cfi_endproc
.LFE1444:
	.size	_Z11regular_avgss, .-_Z11regular_avgss
	.p2align 4,,15
	.globl	_Z8safe_avgss
	.type	_Z8safe_avgss, @function
_Z8safe_avgss:
.LFB1445:
	.cfi_startproc
	testw	%si, %si	# b
	setg	%dl	#, D.32561
	testw	%di, %di	# a
	setle	%al	#, D.32561
	cmpb	%al, %dl	# D.32561, D.32561
	jne	.L6	#,
	movswl	%di, %edi	# a, D.32564
	movswl	%si, %esi	# b, D.32564
	addl	%edi, %esi	# D.32564, D.32564
	movl	%esi, %eax	# D.32564, tmp112
	shrl	$31, %eax	#, tmp112
	addl	%esi, %eax	# D.32564, tmp113
	shrl	%eax	# D.32563
	ret
	.p2align 4,,10
	.p2align 3
.L6:
	movl	%esi, %edx	# b, tmp92
	movl	%edi, %eax	# a, tmp96
	shrw	$15, %dx	#, tmp92
	shrw	$15, %ax	#, tmp96
	addl	%esi, %edx	# b, y
	addl	%edi, %eax	# a, x
	addl	%esi, %edi	# b, D.32562
	sarw	%dx	# y
	sarw	%ax	# x
	addl	%edx, %eax	# y, D.32562
	leal	(%rax,%rax), %edx	#, tmp101
	subl	%edx, %edi	# tmp101, D.32562
	movl	%edi, %esi	# D.32562, tmp105
	shrw	$15, %si	#, tmp105
	addl	%esi, %edi	# tmp105, D.32563
	sarw	%di	# D.32563
	addl	%edi, %eax	# D.32563, D.32563
	ret
	.cfi_endproc
.LFE1445:
	.size	_Z8safe_avgss, .-_Z8safe_avgss
	.p2align 4,,15
	.globl	_Z8add_ovf1ss
	.type	_Z8add_ovf1ss, @function
_Z8add_ovf1ss:
.LFB1446:
	.cfi_startproc
	movswq	%di, %rdi	# a, D.32569
	movswq	%si, %rsi	# b, D.32569
	leaq	32768(%rdi,%rsi), %rax	#, D.32570
	cmpq	$65535, %rax	#, D.32570
	setbe	%al	#, D.32571
	ret
	.cfi_endproc
.LFE1446:
	.size	_Z8add_ovf1ss, .-_Z8add_ovf1ss
	.p2align 4,,15
	.globl	_Z8add_ovf2ss
	.type	_Z8add_ovf2ss, @function
_Z8add_ovf2ss:
.LFB1447:
	.cfi_startproc
	testw	%si, %si	# b
	movswl	%di, %edi	# a, D.32576
	movswl	%si, %esi	# b, D.32576
	js	.L9	#,
	movl	$32767, %eax	#, D.32576
	subl	%esi, %eax	# D.32576, D.32576
	cmpl	%eax, %edi	# D.32576, D.32576
	setg	%al	#, D.32577
	ret
	.p2align 4,,10
	.p2align 3
.L9:
	movl	$-32768, %eax	#, D.32576
	subl	%esi, %eax	# D.32576, D.32576
	cmpl	%eax, %edi	# D.32576, D.32576
	setl	%al	#, D.32577
	ret
	.cfi_endproc
.LFE1447:
	.size	_Z8add_ovf2ss, .-_Z8add_ovf2ss
	.p2align 4,,15
	.globl	_Z9mult_ovf1ss
	.type	_Z9mult_ovf1ss, @function
_Z9mult_ovf1ss:
.LFB1448:
	.cfi_startproc
	movswq	%si, %rsi	# b, D.32582
	movswq	%di, %rdi	# a, r
	imulq	%rsi, %rdi	# D.32582, r
	addq	$32768, %rdi	#, D.32583
	cmpq	$65535, %rdi	#, D.32583
	setbe	%al	#, D.32584
	ret
	.cfi_endproc
.LFE1448:
	.size	_Z9mult_ovf1ss, .-_Z9mult_ovf1ss
	.p2align 4,,15
	.globl	_Z9mult_ovf2ss
	.type	_Z9mult_ovf2ss, @function
_Z9mult_ovf2ss:
.LFB1449:
	.cfi_startproc
	testw	%di, %di	# a
	jle	.L13	#,
	testw	%si, %si	# b
	movswl	%di, %edi	# a, D.32594
	movswl	%si, %esi	# b, D.32594
	jle	.L14	#,
	movl	$32767, %eax	#, tmp82
	cltd
	idivl	%edi	# D.32594
	cmpl	%eax, %esi	# D.32594, D.32594
	setg	%al	#, D.32595
	ret
	.p2align 4,,10
	.p2align 3
.L13:
	cmpw	$0, %si	#, b
	jle	.L16	#,
	movl	$-32768, %eax	#, tmp96
	movswl	%si, %esi	# b, D.32594
	movswl	%di, %edi	# a, D.32594
	cltd
	idivl	%esi	# D.32594
	cmpl	%eax, %edi	# D.32594, D.32594
	setl	%al	#, D.32595
	ret
	.p2align 4,,10
	.p2align 3
.L16:
	movl	$0, %eax	#, D.32595
	je	.L15	#,
	movl	$32767, %eax	#, tmp103
	movswl	%si, %esi	# b, D.32594
	movswl	%di, %edi	# a, D.32594
	cltd
	idivl	%esi	# D.32594
	cmpl	%eax, %edi	# D.32594, D.32594
	setl	%al	#, D.32595
.L15:
	rep ret
	.p2align 4,,10
	.p2align 3
.L14:
	movl	$-32768, %eax	#, tmp89
	cltd
	idivl	%edi	# D.32594
	cmpl	%eax, %esi	# D.32594, D.32594
	setl	%al	#, D.32595
	ret
	.cfi_endproc
.LFE1449:
	.size	_Z9mult_ovf2ss, .-_Z9mult_ovf2ss
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.type	_GLOBAL__sub_I__Z11regular_avgss, @function
_GLOBAL__sub_I__Z11regular_avgss:
.LFB1600:
	.cfi_startproc
	subq	$8, %rsp	#,
	.cfi_def_cfa_offset 16
	movl	$_ZStL8__ioinit, %edi	#,
	call	_ZNSt8ios_base4InitC1Ev	#
	movl	$__dso_handle, %edx	#,
	movl	$_ZStL8__ioinit, %esi	#,
	movl	$_ZNSt8ios_base4InitD1Ev, %edi	#,
	addq	$8, %rsp	#,
	.cfi_def_cfa_offset 8
	jmp	__cxa_atexit	#
	.cfi_endproc
.LFE1600:
	.size	_GLOBAL__sub_I__Z11regular_avgss, .-_GLOBAL__sub_I__Z11regular_avgss
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z11regular_avgss
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu/Linaro 4.8.1-10ubuntu8) 4.8.1"
	.section	.note.GNU-stack,"",@progbits
