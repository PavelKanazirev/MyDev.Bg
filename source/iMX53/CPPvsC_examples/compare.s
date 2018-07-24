	.file	"compare.cpp"
	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.text
	.globl	main
	.type	main, @function
main:
.LFB884:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	addq	%rax, %rdx
	movq	-32(%rbp), %rax
	addq	$8, %rax
	subq	$8, %rsp
	pushq	%rcx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt8count_ifIPPcZ4mainEUlT_E_ENSt15iterator_traitsIS2_E15difference_typeES2_S2_T0_
	addq	$16, %rsp
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE884:
	.size	main, .-main
	.type	_ZSt8count_ifIPPcZ4mainEUlT_E_ENSt15iterator_traitsIS2_E15difference_typeES2_S2_T0_, @function
_ZSt8count_ifIPPcZ4mainEUlT_E_ENSt15iterator_traitsIS2_E15difference_typeES2_S2_T0_:
.LFB888:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	subq	$8, %rsp
	pushq	%rax
	call	_ZN9__gnu_cxx5__ops11__pred_iterIZ4mainEUlT_E_EENS0_10_Iter_predIS2_EES2_
	addq	$16, %rsp
	movq	-32(%rbp), %rdx
	movq	-24(%rbp), %rax
	subq	$8, %rsp
	pushq	%rbx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt10__count_ifIPPcN9__gnu_cxx5__ops10_Iter_predIZ4mainEUlT_E_EEENSt15iterator_traitsIS5_E15difference_typeES5_S5_T0_
	addq	$16, %rsp
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE888:
	.size	_ZSt8count_ifIPPcZ4mainEUlT_E_ENSt15iterator_traitsIS2_E15difference_typeES2_S2_T0_, .-_ZSt8count_ifIPPcZ4mainEUlT_E_ENSt15iterator_traitsIS2_E15difference_typeES2_S2_T0_
	.type	_ZSt4moveIRZ4mainEUlT_E_EONSt16remove_referenceIS0_E4typeEOS0_, @function
_ZSt4moveIRZ4mainEUlT_E_EONSt16remove_referenceIS0_E4typeEOS0_:
.LFB890:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE890:
	.size	_ZSt4moveIRZ4mainEUlT_E_EONSt16remove_referenceIS0_E4typeEOS0_, .-_ZSt4moveIRZ4mainEUlT_E_EONSt16remove_referenceIS0_E4typeEOS0_
	.type	_ZN9__gnu_cxx5__ops11__pred_iterIZ4mainEUlT_E_EENS0_10_Iter_predIS2_EES2_, @function
_ZN9__gnu_cxx5__ops11__pred_iterIZ4mainEUlT_E_EENS0_10_Iter_predIS2_EES2_:
.LFB889:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$16, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	16(%rbp), %rdi
	call	_ZSt4moveIRZ4mainEUlT_E_EONSt16remove_referenceIS0_E4typeEOS0_
	leaq	-25(%rbp), %rax
	subq	$8, %rsp
	pushq	%r12
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx5__ops10_Iter_predIZ4mainEUlT_E_EC1ES3_
	addq	$16, %rsp
	movl	%ebx, %eax
	movq	-24(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L10
	call	__stack_chk_fail@PLT
.L10:
	leaq	-16(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE889:
	.size	_ZN9__gnu_cxx5__ops11__pred_iterIZ4mainEUlT_E_EENS0_10_Iter_predIS2_EES2_, .-_ZN9__gnu_cxx5__ops11__pred_iterIZ4mainEUlT_E_EENS0_10_Iter_predIS2_EES2_
	.type	_ZSt10__count_ifIPPcN9__gnu_cxx5__ops10_Iter_predIZ4mainEUlT_E_EEENSt15iterator_traitsIS5_E15difference_typeES5_S5_T0_, @function
_ZSt10__count_ifIPPcN9__gnu_cxx5__ops10_Iter_predIZ4mainEUlT_E_EEENSt15iterator_traitsIS5_E15difference_typeES5_S5_T0_:
.LFB891:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	$0, -8(%rbp)
.L14:
	movq	-24(%rbp), %rax
	cmpq	-32(%rbp), %rax
	je	.L12
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	16(%rbp), %rdi
	call	_ZN9__gnu_cxx5__ops10_Iter_predIZ4mainEUlT_E_EclIPPcEEbS2_
	testb	%al, %al
	je	.L13
	addq	$1, -8(%rbp)
.L13:
	addq	$8, -24(%rbp)
	jmp	.L14
.L12:
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE891:
	.size	_ZSt10__count_ifIPPcN9__gnu_cxx5__ops10_Iter_predIZ4mainEUlT_E_EEENSt15iterator_traitsIS5_E15difference_typeES5_S5_T0_, .-_ZSt10__count_ifIPPcN9__gnu_cxx5__ops10_Iter_predIZ4mainEUlT_E_EEENSt15iterator_traitsIS5_E15difference_typeES5_S5_T0_
	.align 2
	.type	_ZN9__gnu_cxx5__ops10_Iter_predIZ4mainEUlT_E_EC2ES3_, @function
_ZN9__gnu_cxx5__ops10_Iter_predIZ4mainEUlT_E_EC2ES3_:
.LFB893:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$8, %rsp
	movq	%rdi, -8(%rbp)
	leaq	16(%rbp), %rdi
	call	_ZSt4moveIRZ4mainEUlT_E_EONSt16remove_referenceIS0_E4typeEOS0_
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE893:
	.size	_ZN9__gnu_cxx5__ops10_Iter_predIZ4mainEUlT_E_EC2ES3_, .-_ZN9__gnu_cxx5__ops10_Iter_predIZ4mainEUlT_E_EC2ES3_
	.set	_ZN9__gnu_cxx5__ops10_Iter_predIZ4mainEUlT_E_EC1ES3_,_ZN9__gnu_cxx5__ops10_Iter_predIZ4mainEUlT_E_EC2ES3_
	.align 2
	.type	_ZZ4mainENKUlT_E_clIPcEEDaS_, @function
_ZZ4mainENKUlT_E_clIPcEEDaS_:
.LFB896:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	cmpl	$3, %eax
	sete	%al
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE896:
	.size	_ZZ4mainENKUlT_E_clIPcEEDaS_, .-_ZZ4mainENKUlT_E_clIPcEEDaS_
	.align 2
	.type	_ZN9__gnu_cxx5__ops10_Iter_predIZ4mainEUlT_E_EclIPPcEEbS2_, @function
_ZN9__gnu_cxx5__ops10_Iter_predIZ4mainEUlT_E_EclIPPcEEbS2_:
.LFB895:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZZ4mainENKUlT_E_clIPcEEDaS_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE895:
	.size	_ZN9__gnu_cxx5__ops10_Iter_predIZ4mainEUlT_E_EclIPPcEEbS2_, .-_ZN9__gnu_cxx5__ops10_Iter_predIZ4mainEUlT_E_EclIPPcEEbS2_
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
