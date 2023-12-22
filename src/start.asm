bits 32
align 4

global start

section .text
start:
	
	; Set up stack pointer.
	mov esp, stack_end

	cli ;disable interupts I think

	extern main
	call main
	
	hlt


stack_begin:
    RESB 4096  ; Reserve 4 KiB stack space
stack_end:
