	global		_ft_read
	section		.text
_ft_read:
	mov		rax, 0x02000003
	syscall
	jnc		.end
	mov		rax, -1
.end:
	ret