global		ft_strcmp
ft_strcmp:
.while:
	mov		rax, 0		;init
	mov		rdx, 0
	mov		al, [rdi]	;str1[]
	mov		dl, [rsi]	;str2[]
	cmp		al, 0
	jz		.exit
	cmp		dl, 0
	jz		.exit
	cmp		al, dl
	jne		.exit
	inc		rdi
	inc		rsi
	jmp		.while
.exit:
	sub		rax, rdx
	ret