global		ft_strcpy
section		.text
ft_strcpy:
		mov		rax, rsi
		mov		rdx, rdi
.while:
		cmp		byte [rsi], 0
		jz		.exit
		mov		al, [rsi]
		mov		[rdi], al
		inc		rsi
		inc		rdi
		jmp		.while
.exit:
		mov		byte [rdi], 0
		mov		rax, rdx
		ret