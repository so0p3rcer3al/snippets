	.file	"hello.cpp"
# GNU C++ (Ubuntu/Linaro 4.8.1-10ubuntu9) version 4.8.1 (x86_64-linux-gnu)
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
	.globl	_Z15get_field0_compv
	.type	_Z15get_field0_compv, @function
_Z15get_field0_compv:
.LFB1445:
	.cfi_startproc
	movzbl	bf_R(%rip), %eax	# bf_R, D.32333
	andl	$127, %eax	#, D.32333
	ret
	.cfi_endproc
.LFE1445:
	.size	_Z15get_field0_compv, .-_Z15get_field0_compv
	.p2align 4,,15
	.globl	_Z15get_field0_origv
	.type	_Z15get_field0_origv, @function
_Z15get_field0_origv:
.LFB1446:
	.cfi_startproc
	movzbl	bf(%rip), %eax	# bf.store, D.32337
	andl	$127, %eax	#, D.32337
	ret
	.cfi_endproc
.LFE1446:
	.size	_Z15get_field0_origv, .-_Z15get_field0_origv
	.p2align 4,,15
	.globl	_Z15get_field1_compv
	.type	_Z15get_field1_compv, @function
_Z15get_field1_compv:
.LFB1447:
	.cfi_startproc
	movzbl	bf_R(%rip), %eax	# bf_R, D.32340
	shrb	$7, %al	#, D.32340
	ret
	.cfi_endproc
.LFE1447:
	.size	_Z15get_field1_compv, .-_Z15get_field1_compv
	.p2align 4,,15
	.globl	_Z15get_field1_origv
	.type	_Z15get_field1_origv, @function
_Z15get_field1_origv:
.LFB1448:
	.cfi_startproc
	movzbl	bf(%rip), %eax	# bf.store, D.32344
	shrb	$7, %al	#, D.32344
	ret
	.cfi_endproc
.LFE1448:
	.size	_Z15get_field1_origv, .-_Z15get_field1_origv
	.p2align 4,,15
	.globl	_Z15set_field0_comph
	.type	_Z15set_field0_comph, @function
_Z15set_field0_comph:
.LFB1449:
	.cfi_startproc
	movzbl	bf_R(%rip), %eax	# bf_R.a, tmp66
	andl	$127, %edi	#, tmp63
	andl	$-128, %eax	#, tmp66
	orl	%edi, %eax	# tmp63, tmp66
	movb	%al, bf_R(%rip)	# tmp66, bf_R.a
	ret
	.cfi_endproc
.LFE1449:
	.size	_Z15set_field0_comph, .-_Z15set_field0_comph
	.p2align 4,,15
	.globl	_Z15set_field0_origh
	.type	_Z15set_field0_origh, @function
_Z15set_field0_origh:
.LFB1450:
	.cfi_startproc
	movzbl	bf(%rip), %eax	# bf.store, tmp66
	andl	$-128, %eax	#, tmp66
	orl	%edi, %eax	# n, tmp66
	movb	%al, bf(%rip)	# tmp66, bf.store
	ret
	.cfi_endproc
.LFE1450:
	.size	_Z15set_field0_origh, .-_Z15set_field0_origh
	.p2align 4,,15
	.globl	_Z15set_field1_comph
	.type	_Z15set_field1_comph, @function
_Z15set_field1_comph:
.LFB1451:
	.cfi_startproc
	movzbl	bf_R(%rip), %eax	# bf_R.b, tmp66
	sall	$7, %edi	#, tmp63
	andl	$127, %eax	#, tmp66
	orl	%edi, %eax	# tmp63, tmp66
	movb	%al, bf_R(%rip)	# tmp66, bf_R.b
	ret
	.cfi_endproc
.LFE1451:
	.size	_Z15set_field1_comph, .-_Z15set_field1_comph
	.p2align 4,,15
	.globl	_Z15set_field1_origh
	.type	_Z15set_field1_origh, @function
_Z15set_field1_origh:
.LFB1452:
	.cfi_startproc
	movzbl	bf(%rip), %eax	# bf.store, D.32359
	sall	$7, %edi	#, tmp68
	andl	$127, %eax	#, D.32359
	orl	%eax, %edi	# D.32359, tmp68
	movb	%dil, bf(%rip)	# tmp68, bf.store
	ret
	.cfi_endproc
.LFE1452:
	.size	_Z15set_field1_origh, .-_Z15set_field1_origh
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.type	_GLOBAL__sub_I_bf, @function
_GLOBAL__sub_I_bf:
.LFB1604:
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
.LFE1604:
	.size	_GLOBAL__sub_I_bf, .-_GLOBAL__sub_I_bf
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_bf
	.local	bf_R
	.comm	bf_R,1,1
	.globl	bf
	.bss
	.type	bf, @object
	.size	bf, 1
bf:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1"
	.section	.note.GNU-stack,"",@progbits
