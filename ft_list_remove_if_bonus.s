global		_ft_list_remove_if
extern		_free
_ft_list_remove_if:
	mov		r15, rdi	;begin_list
	mov		r14, rsi	;data_ref
	mov		r13, rdx	;cmp
	mov		r12, rcx	;free_fct
	mov		rbx, [r15]	;first_elmt
.while:
	cmp		rbx, 0
	je		.exit
	mov		rdi, [rbx]	;data_elemt
	mov		rsi, r14
	call	r13
	cmp		rax, 0
	jne		.next
	;delete
.next:
	mov		rbx, [rbx + 8]
	jmp		.while
.exit:
	mov		rax, 0
	ret