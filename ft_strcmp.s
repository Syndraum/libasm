global		_ft_strcmp
_ft_strcmp:
.while:
	mov		al, [rdi]
	mov		dl, [rsi]
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
	cmp		al, dl
	je		.egal
	ja		.sup
	mov		rax, -1
	jmp		.return
.egal:
	mov		rax, 0
	jmp		.return
.sup:
	mov		rax, 1
.return:
	ret 