	global		ft_write
	section		.text
ft_write:
	mov		rax, 0x02000004
	syscall
	jnc		.end
	mov		rax, -1
.end:
	ret