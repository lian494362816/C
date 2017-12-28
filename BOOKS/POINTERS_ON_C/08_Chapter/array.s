	.file	"array.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$39912, %rsp
	movl	%edi, -40020(%rbp)
	movq	%rsi, -40032(%rbp)
	movl	$0, -40004(%rbp)
	jmp	.L2
.L3:
	movl	-40004(%rbp), %eax
	cltq
	movl	$0, -40000(%rbp,%rax,4)
	addl	$1, -40004(%rbp)
.L2:
	cmpl	$9999, -40004(%rbp)
	jle	.L3
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
