global		_ft_atoi_base
extern		_ft_strlen
extern		_ft_strstr
section		.text
_ft_atoi_base:
	mov		r14, rdi	;number
	mov		r15, rsi	;base
	mov		rdi, rsi
	call	_ft_strlen
	mov		r12, rax	;len base
	cmp		rax, 2		;len base < 2
	jl		.error
	mov		r13, r15	;cursor
.while:
	cmp		byte[r13], 0
	je		.end_while
.if:
	cmp		byte[r13], 32
	je		.error
	cmp		byte[r13], 45
	je		.error
	cmp		byte[r13], 43
	je		.error
	cmp		byte[r13], 9
	jl		.end_if
	cmp		byte[r13], 14
	jle		.error

.end_if:
	mov		sil, byte [r13]
	mov		rdi, r13
	inc		rdi
	mov		rax, 0
	call	_ft_strstr
	cmp		al, -1
	jne		.error
	inc		r13
	jmp		.while

.end_while:
	mov		rdi, r14	;number *
	mov		r14, 1		;signe
	mov		rsi, 0		;result
.wspace:
	cmp		byte[rdi], 0
	je		.end
	cmp		byte[rdi], 9
	jl		.signe
	cmp		byte[rdi], 14
	jle		.continue
	cmp		byte[rdi], ' '
	jne		.signe
.continue:
	inc		rdi
	jmp		.wspace

.signe:
	cmp		byte[rdi], 0
	je		.end
	cmp		byte[rdi], '-'
	je		.minus
	cmp		byte[rdi], '+'
	je		.plus
	jmp		.number
.minus:
	neg		r14
.plus:
	inc		rdi
	jmp		.signe

.number:
	cmp		byte[rdi], 0
	je		.end
	push	rdi
	push	rsi
	mov		rsi, 0
	mov		sil, byte[rdi]
	mov		rdi, r15
	call	_ft_strstr
	pop		rsi
	pop		rdi
	cmp		al, -1
	je		.end
	imul	rsi, r12
	add		rsi, rax
	inc		rdi
	jmp		.number

.end:
	imul	rsi, r14
	mov		rax, rsi
	ret

.error:
	mov rax, -42
	ret

