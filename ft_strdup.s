global		_ft_strdup
extern		_malloc
extern		_ft_strlen
extern		_ft_strcpy
_ft_strdup:
	mov		r14, rdi
	call	_ft_strlen
	inc		rax
	mov		rdi, rax
	call	_malloc
	; mov		rdi, rax
	; mov		rsi, r14
	; call	_ft_strcpy
	mov		rax, 0
	ret