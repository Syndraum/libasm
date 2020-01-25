	global		_ft_write
	section		.text
_ft_write:
	mov		r14, rdx
.write:
	mov		rax, 0x02000004
	syscall
	jc		.error
	mov		rax, r14
	jmp		.end
.error:
	mov		rax, -1
.end:
	ret