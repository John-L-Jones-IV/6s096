	.file	"matrix2.c"
	.text
	.globl	allocate_matrix
	.type	allocate_matrix, @function
allocate_matrix:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$24, %edi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-24(%rbp), %rax
	imulq	-32(%rbp), %rax
	salq	$2, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 16(%rax)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	allocate_matrix, .-allocate_matrix
	.globl	destroy_matrix
	.type	destroy_matrix, @function
destroy_matrix:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	destroy_matrix, .-destroy_matrix
	.section	.rodata
.LC0:
	.string	"%zu %zu"
.LC1:
	.string	"%d"
	.text
	.globl	read_matrix
	.type	read_matrix, @function
read_matrix:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -56(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-40(%rbp), %rcx
	leaq	-48(%rbp), %rdx
	movq	-56(%rbp), %rax
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf@PLT
	movq	-40(%rbp), %rdx
	movq	-48(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	allocate_matrix
	movq	%rax, -16(%rbp)
	movq	$0, -32(%rbp)
	jmp	.L5
.L8:
	movq	$0, -24(%rbp)
	jmp	.L6
.L7:
	movq	-16(%rbp), %rax
	movq	16(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	imulq	-24(%rbp), %rax
	movq	%rax, %rcx
	movq	-32(%rbp), %rax
	addq	%rcx, %rax
	salq	$2, %rax
	addq	%rax, %rdx
	movq	-56(%rbp), %rax
	leaq	.LC1(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf@PLT
	addq	$1, -24(%rbp)
.L6:
	movq	-40(%rbp), %rax
	cmpq	%rax, -24(%rbp)
	jb	.L7
	addq	$1, -32(%rbp)
.L5:
	movq	-48(%rbp), %rax
	cmpq	%rax, -32(%rbp)
	jb	.L8
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L10
	call	__stack_chk_fail@PLT
.L10:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	read_matrix, .-read_matrix
	.section	.rodata
	.align 8
.LC2:
	.string	"Error: tried to multiply (%zux%zu)x(%zux%zu)"
	.text
	.globl	mat_mul
	.type	mat_mul, @function
mat_mul:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-48(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, %rdx
	je	.L12
	movq	-48(%rbp), %rax
	movq	8(%rax), %rsi
	movq	-48(%rbp), %rax
	movq	(%rax), %rcx
	movq	-40(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	%rsi, %r8
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$1, %edi
	call	exit@PLT
.L12:
	movq	-48(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	allocate_matrix
	movq	%rax, -8(%rbp)
	movq	$0, -32(%rbp)
	jmp	.L13
.L18:
	movq	$0, -24(%rbp)
	jmp	.L14
.L17:
	movq	-8(%rbp), %rax
	movq	16(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	imulq	-24(%rbp), %rax
	movq	%rax, %rcx
	movq	-32(%rbp), %rax
	addq	%rcx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	movl	$0, (%rax)
	movq	$0, -16(%rbp)
	jmp	.L15
.L16:
	movq	-8(%rbp), %rax
	movq	16(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	imulq	-24(%rbp), %rax
	movq	%rax, %rcx
	movq	-32(%rbp), %rax
	addq	%rcx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	movl	(%rax), %ecx
	movq	-40(%rbp), %rax
	movq	16(%rax), %rdx
	movq	-16(%rbp), %rsi
	movq	-24(%rbp), %rax
	addq	%rax, %rsi
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	imulq	%rsi, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movq	-48(%rbp), %rax
	movq	16(%rax), %rsi
	movq	-48(%rbp), %rax
	movq	(%rax), %rax
	imulq	-24(%rbp), %rax
	movq	%rax, %rdi
	movq	-16(%rbp), %rax
	addq	%rdi, %rax
	salq	$2, %rax
	addq	%rsi, %rax
	movl	(%rax), %eax
	imull	%eax, %edx
	movq	-8(%rbp), %rax
	movq	16(%rax), %rsi
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	imulq	-24(%rbp), %rax
	movq	%rax, %rdi
	movq	-32(%rbp), %rax
	addq	%rdi, %rax
	salq	$2, %rax
	addq	%rsi, %rax
	addl	%ecx, %edx
	movl	%edx, (%rax)
	addq	$1, -16(%rbp)
.L15:
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, -16(%rbp)
	jb	.L16
	addq	$1, -24(%rbp)
.L14:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	cmpq	%rax, -24(%rbp)
	jb	.L17
	addq	$1, -32(%rbp)
.L13:
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, -32(%rbp)
	jb	.L18
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	mat_mul, .-mat_mul
	.section	.rodata
.LC3:
	.string	"%zu %zu\n"
.LC4:
	.string	"%d "
	.text
	.globl	write_matrix
	.type	write_matrix, @function
write_matrix:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	8(%rax), %rcx
	movq	-32(%rbp), %rax
	movq	(%rax), %rdx
	movq	-24(%rbp), %rax
	leaq	.LC3(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movq	$0, -16(%rbp)
	jmp	.L21
.L24:
	movq	$0, -8(%rbp)
	jmp	.L22
.L23:
	movq	-32(%rbp), %rax
	movq	16(%rax), %rdx
	movq	-32(%rbp), %rax
	movq	8(%rax), %rax
	imulq	-16(%rbp), %rax
	movq	%rax, %rcx
	movq	-8(%rbp), %rax
	addq	%rcx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movq	-24(%rbp), %rax
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	addq	$1, -8(%rbp)
.L22:
	movq	-32(%rbp), %rax
	movq	8(%rax), %rax
	cmpq	%rax, -8(%rbp)
	jb	.L23
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$10, %edi
	call	fputc@PLT
	addq	$1, -16(%rbp)
.L21:
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, -16(%rbp)
	jb	.L24
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	write_matrix, .-write_matrix
	.section	.rodata
.LC5:
	.string	"r"
.LC6:
	.string	"matrix2.11.in"
.LC7:
	.string	"w"
.LC8:
	.string	"matrix2.11.out"
	.text
	.globl	main
	.type	main, @function
main:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	leaq	.LC5(%rip), %rsi
	leaq	.LC6(%rip), %rdi
	call	fopen@PLT
	movq	%rax, -40(%rbp)
	leaq	.LC7(%rip), %rsi
	leaq	.LC8(%rip), %rdi
	call	fopen@PLT
	movq	%rax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	read_matrix
	movq	%rax, -24(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	read_matrix
	movq	%rax, -16(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	movq	-16(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	mat_mul
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	write_matrix
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	destroy_matrix
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	destroy_matrix
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	destroy_matrix
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
