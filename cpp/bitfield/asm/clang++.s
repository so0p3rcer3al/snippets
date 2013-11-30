	.file	"hello.cpp"
	.text
	.globl	_Z15get_field0_compv
	.align	16, 0x90
	.type	_Z15get_field0_compv,@function
_Z15get_field0_compv:                   # @_Z15get_field0_compv
	.cfi_startproc
# BB#0:
	movzbl	bf_R.0(%rip), %eax
	andl	$127, %eax
	ret
.Ltmp0:
	.size	_Z15get_field0_compv, .Ltmp0-_Z15get_field0_compv
	.cfi_endproc

	.globl	_Z15get_field0_origv
	.align	16, 0x90
	.type	_Z15get_field0_origv,@function
_Z15get_field0_origv:                   # @_Z15get_field0_origv
	.cfi_startproc
# BB#0:
	movzbl	bf(%rip), %eax
	andl	$127, %eax
	ret
.Ltmp1:
	.size	_Z15get_field0_origv, .Ltmp1-_Z15get_field0_origv
	.cfi_endproc

	.globl	_Z15get_field1_compv
	.align	16, 0x90
	.type	_Z15get_field1_compv,@function
_Z15get_field1_compv:                   # @_Z15get_field1_compv
	.cfi_startproc
# BB#0:
	movb	bf_R.0(%rip), %al
	shrb	$7, %al
	movzbl	%al, %eax
	ret
.Ltmp2:
	.size	_Z15get_field1_compv, .Ltmp2-_Z15get_field1_compv
	.cfi_endproc

	.globl	_Z15get_field1_origv
	.align	16, 0x90
	.type	_Z15get_field1_origv,@function
_Z15get_field1_origv:                   # @_Z15get_field1_origv
	.cfi_startproc
# BB#0:
	movb	bf(%rip), %al
	shrb	$7, %al
	movzbl	%al, %eax
	ret
.Ltmp3:
	.size	_Z15get_field1_origv, .Ltmp3-_Z15get_field1_origv
	.cfi_endproc

	.globl	_Z15set_field0_comph
	.align	16, 0x90
	.type	_Z15set_field0_comph,@function
_Z15set_field0_comph:                   # @_Z15set_field0_comph
	.cfi_startproc
# BB#0:
	movb	bf_R.0(%rip), %al
	andb	$-128, %al
	andb	$127, %dil
	orb	%al, %dil
	movb	%dil, bf_R.0(%rip)
	ret
.Ltmp4:
	.size	_Z15set_field0_comph, .Ltmp4-_Z15set_field0_comph
	.cfi_endproc

	.globl	_Z15set_field0_origh
	.align	16, 0x90
	.type	_Z15set_field0_origh,@function
_Z15set_field0_origh:                   # @_Z15set_field0_origh
	.cfi_startproc
# BB#0:
	movb	bf(%rip), %al
	andb	$-128, %al
	orb	%dil, %al
	movb	%al, bf(%rip)
	ret
.Ltmp5:
	.size	_Z15set_field0_origh, .Ltmp5-_Z15set_field0_origh
	.cfi_endproc

	.globl	_Z15set_field1_comph
	.align	16, 0x90
	.type	_Z15set_field1_comph,@function
_Z15set_field1_comph:                   # @_Z15set_field1_comph
	.cfi_startproc
# BB#0:
	movb	bf_R.0(%rip), %al
	andb	$127, %al
	shlb	$7, %dil
	orb	%al, %dil
	movb	%dil, bf_R.0(%rip)
	ret
.Ltmp6:
	.size	_Z15set_field1_comph, .Ltmp6-_Z15set_field1_comph
	.cfi_endproc

	.globl	_Z15set_field1_origh
	.align	16, 0x90
	.type	_Z15set_field1_origh,@function
_Z15set_field1_origh:                   # @_Z15set_field1_origh
	.cfi_startproc
# BB#0:
	movb	bf(%rip), %al
	andb	$127, %al
	shlb	$7, %dil
	orb	%al, %dil
	movb	%dil, bf(%rip)
	ret
.Ltmp7:
	.size	_Z15set_field1_origh, .Ltmp7-_Z15set_field1_origh
	.cfi_endproc

	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	_GLOBAL__I_a,@function
_GLOBAL__I_a:                           # @_GLOBAL__I_a
	.cfi_startproc
# BB#0:
	pushq	%rax
.Ltmp9:
	.cfi_def_cfa_offset 16
	movl	$_ZStL8__ioinit, %edi
	callq	_ZNSt8ios_base4InitC1Ev
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	movl	$_ZStL8__ioinit, %esi
	movl	$__dso_handle, %edx
	popq	%rax
	jmp	__cxa_atexit            # TAILCALL
.Ltmp10:
	.size	_GLOBAL__I_a, .Ltmp10-_GLOBAL__I_a
	.cfi_endproc

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.type	bf,@object              # @bf
	.bss
	.globl	bf
bf:
	.zero	1
	.size	bf, 1

	.type	bf_R.0,@object          # @bf_R.0
	.local	bf_R.0
	.comm	bf_R.0,1,1
	.section	.init_array,"aw",@init_array
	.align	8
	.quad	_GLOBAL__I_a

	.section	".note.GNU-stack","",@progbits
