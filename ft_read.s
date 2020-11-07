	global		ft_read
	section		.text
ft_read:
	mov		rax, 0x02000003
	syscall
	jnc		.end
	mov		rax, -1
.end:
	ret