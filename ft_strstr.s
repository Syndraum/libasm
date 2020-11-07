global		ft_strstr
ft_strstr:
	mov		rax, rdi
.while:
	cmp		byte[rax], 0
	je		.eof
	cmp		byte[rax], sil
	je		.end_while
	inc		rax
	jmp		.while
.end_while:
	sub		rax, rdi
	ret
.eof:
	mov rax, -1
	ret