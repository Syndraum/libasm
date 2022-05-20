global		_ft_strlen
section		.text
_ft_strlen:
		mov		rax, rdi
.while:
		cmp		byte [rax], 0
		jz		.exit
		inc		rax
		jmp		.while
.exit:
		sub		rax, rdi
		ret