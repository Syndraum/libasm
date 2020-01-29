global		_ft_atoi_base
extern		_ft_strlen
section		.text
		push	rsi
		push	rdi
		call _ft_strlen
		cmp rax, 2
		jl .error
		jmp .exit
.error:
	mov rax, 0
.exit:
	ret
