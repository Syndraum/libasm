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
	pop		rdi		;pointer **list
	je		.exit
	mov		r12, rax		;pointeur list
	mov		[r12], rsi		;data -> list.data
	mov		r15, [rdi]		;*list (fisrt elmt)
	mov		[r12 + 8], r15	;*list -> list.next
	mov		[rdi], rax		;*new_elmt -> *list

.exit:
	mov rax, 0
	ret
