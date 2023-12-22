; TODO: interupt handlers

section .text

global idt_flush
extern idtr

idt_flush:
	lidt (idtr)
	ret

exception:
	pushad

	popad
	iret
