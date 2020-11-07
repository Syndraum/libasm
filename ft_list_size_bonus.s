global ft_list_size
ft_list_size:
	mov		rax, 0
.while:
	cmp		rdi, 0
	je		.exit
	inc		rax
	mov		rdi, [rdi + 8]
	jmp		.while
.exit:
	ret