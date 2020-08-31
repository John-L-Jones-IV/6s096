	.file	"floating.c"
	.text
	.section	.rodata
.LC0:
	.string	"1."
.LC1:
	.string	"0."
.LC2:
	.string	"%ld\n"
.LC3:
	.string	"%u"
.LC4:
	.string	" * 2^%d\n"
	.text
	.globl	print_float
	.type	print_float, @function
print_float:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movss	%xmm0, -44(%rbp)
	movss	-44(%rbp), %xmm0
	movss	%xmm0, -20(%rbp)
	movl	-20(%rbp), %eax
	shrl	$31, %eax
	movl	%eax, -8(%rbp)
	movl	-20(%rbp), %eax
	shrl	$23, %eax
	andl	$255, %eax
	movl	%eax, -16(%rbp)
	movl	-20(%rbp), %eax
	andl	$8388607, %eax
	movl	%eax, -4(%rbp)
	cmpl	$0, -8(%rbp)
	je	.L2
	movq	-40(%rbp), %rax
	movq	%rax, %rsi
	movl	$45, %edi
	call	fputc@PLT
.L2:
	cmpl	$0, -16(%rbp)
	je	.L3
	movq	-40(%rbp), %rax
	movq	%rax, %rcx
	movl	$2, %edx
	movl	$1, %esi
	leaq	.LC0(%rip), %rdi
	call	fwrite@PLT
	subl	$127, -16(%rbp)
	jmp	.L4
.L3:
	movq	-40(%rbp), %rax
	movq	%rax, %rcx
	movl	$2, %edx
	movl	$1, %esi
	leaq	.LC1(%rip), %rdi
	call	fwrite@PLT
	subl	$126, -16(%rbp)
.L4:
	movl	$22, -12(%rbp)
	jmp	.L5
.L6:
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-12(%rbp), %eax
	movl	-4(%rbp), %edx
	movl	%eax, %ecx
	shrl	%cl, %edx
	movl	%edx, %eax
	andl	$1, %eax
	movl	%eax, %edx
	movq	-40(%rbp), %rax
	leaq	.LC3(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	subl	$1, -12(%rbp)
.L5:
	cmpl	$0, -12(%rbp)
	jns	.L6
	movl	-16(%rbp), %edx
	movq	-40(%rbp), %rax
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	print_float, .-print_float
	.section	.rodata
.LC5:
	.string	"r"
.LC6:
	.string	"floating.1.in"
.LC7:
	.string	"w"
.LC8:
	.string	"floating.1.out"
.LC9:
	.string	"%zu"
.LC10:
	.string	"%f"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC5(%rip), %rsi
	leaq	.LC6(%rip), %rdi
	call	fopen@PLT
	movq	%rax, -24(%rbp)
	leaq	.LC7(%rip), %rsi
	leaq	.LC8(%rip), %rdi
	call	fopen@PLT
	movq	%rax, -16(%rbp)
	leaq	-40(%rbp), %rdx
	movq	-24(%rbp), %rax
	leaq	.LC9(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf@PLT
	movq	$0, -32(%rbp)
	jmp	.L8
.L9:
	leaq	-44(%rbp), %rdx
	movq	-24(%rbp), %rax
	leaq	.LC10(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf@PLT
	movl	-44(%rbp), %edx
	movq	-16(%rbp), %rax
	movl	%edx, -52(%rbp)
	movss	-52(%rbp), %xmm0
	movq	%rax, %rdi
	call	print_float
	addq	$1, -32(%rbp)
.L8:
	movq	-40(%rbp), %rax
	cmpq	%rax, -32(%rbp)
	jb	.L9
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L11
	call	__stack_chk_fail@PLT
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
