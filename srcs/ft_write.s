	global		_ft_write
	section		.text
_ft_write:
	mov		rax, 0x02000004
	syscall
	jnc		.end
	mov		rax, -1
.end:
	ret