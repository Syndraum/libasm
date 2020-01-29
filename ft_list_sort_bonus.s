global		_ft_list_sort
extern		_ft_list_size
_ft_list_sort:
	mov		r15, rdi	;begin
	mov		r14, rsi	;function
	mov		r13, [r15]	;first_elemt
	mov		rdi, r13
	call	_ft_list_size
	mov		r12, rax	;size
.while:
	cmp		r12, 0
	je		.exit
	mov		r13, [r15]
.loops:
	mov		rdi, [r13]
	mov		rdx, [r13 + 8]
	cmp		rdx, 0
	je		.end_loop
	mov		rsi, [rdx]
	call	r14
	cmp		rax, 0
	jl		.skip
	mov		rdi, [r13 + 8]	;second elmt
	mov		rsi, [rdi]		;str 2nd
	mov		rdx, [r13]		;str 1er
	mov		[rdi], rdx
	mov		[r13], rsi
.skip:		
	mov		r13, [r13 + 8]
	jmp	.loops
.end_loop:
	dec		r12
	jmp		.while
.exit:
	mov		rax, 0
	ret
	