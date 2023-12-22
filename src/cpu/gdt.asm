section .text

extern gdtr
global gdt_flush

gdt_flush: ;lol this is going to be easier in asm than c
	lgdt (gdtr) ; load gdt
