%include        'ft_strlen.s'
		global		_main

		section		.text
_main:
		mov		rdi, message
		call	ft_strlen
		mov		rdx, rax
		mov		rax, 0x02000004
		mov		rdi, 1
		mov		rsi, message
		syscall
_exit:	
		mov		rax, 0x02000001
		xor		rdi, rdi
		syscall

		section		.data
message:
		db			"Hello, World tfweyvb h b nhbu bnijb ub ijnybinj", 10, 0