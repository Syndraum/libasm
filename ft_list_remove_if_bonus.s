global		ft_list_remove_if
extern		free
extern		_print_list
ft_list_remove_if:
	mov		r15, rdi	;begin_list
	mov		r14, rsi	;data_ref
	mov		r13, rdx	;cmp
	mov		r12, rcx	;free_fct
	mov		rbx, [r15]	;cursor
	mov		rdi, r15	;prec
.while:
	cmp		rbx, 0
	je		.exit
	push	rdi			;push prec
	mov		rdi, [rbx]	;data_elemt
	mov		rsi, r14
	mov		rax, 0
	call	r13
	pop		rdi			;pop prec
	cmp		rax, 0
	jne		.skip
	mov		rsi, [rbx + 8]	; rsi <- cursor.next
	mov		[rdi], rsi		; prec <- next
	push	rdi			;push prec
	mov		rdi, [rbx]
	call	r12			;free_data
	mov		rdi, rbx
	call	free		;free_elmt
	pop		rdi			;pop prec
	jmp		.next
.skip:
	mov		rdi, rbx
	add		rdi, 8
.next:
	mov		rbx, [rbx + 8]
	jmp		.while
.exit:
	mov		rax, 0
	ret