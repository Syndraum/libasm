global		ft_atoi_base
extern		ft_strlen
extern		ft_strstr
section		.text
ft_atoi_base:
	mov		r14, rdi	;number
	mov		r15, rsi	;base
	mov		rdi, rsi
	call	ft_strlen
	mov		r12, rax	;len base
	cmp		rax, 2		;len base < 2
	jl		.error
	mov		r13, r15	;cursor
.while:
	cmp		byte[r13], 0
	je		.end_while
.if:
	cmp		byte[r13], ' '
	je		.error
	cmp		byte[r13], '+'
	je		.error
	cmp		byte[r13], '-'
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
	call	ft_strstr
	cmp		al, -1
	jne		.error
	inc		r13
	jmp		.while

.end_while:
	mov		rdi, r14	;number *
	mov		r14, 1		;signe
	mov		rsi, 0		;result
.wspace:				;whitespace ? continue : signe
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

.signe:		;signe ? 
	cmp		byte[rdi], 0
	je		.end
	cmp		byte[rdi], '-'
	je		.minus
	cmp		byte[rdi], '+'
	je		.plus
	jmp		.number
.minus:
	neg		r14		;invert sign
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
	call	ft_strstr
	pop		rsi
	pop		rdi
	cmp		al, -1
	je		.end
	imul	rsi, r12	;number*base
	add		rsi, rax	;number+index
	inc		rdi
	jmp		.number

.end:
	imul	rsi, r14
	mov		rax, rsi
	ret

.error:
	mov rax, 0
	ret

