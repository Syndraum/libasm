global		_ft_list_push_front
extern		_malloc
_ft_list_push_front:
	mov		rax, 0
	cmp		rdi, 0
	je		.exit
	push	rdi
	push	rsi
	mov		rdi, 16
	call	_malloc
	pop		rsi		;data
	pop		rdi		;pointer
	je		.exit
	mov		r12, rax
	mov		[r12], rsi
	mov		r15, [rdi]
	mov		[r12 + 8], r15
	mov		[rdi], rax

.exit:
	mov rax, 0
	ret
