#include "stdint.h"
#include "stdbool.h"
#include "cpu.h"

struct InterruptDescriptor32 {
   uint16_t offset_1;        // offset bits 0..15
   uint16_t selector;        // a code segment selector in GDT or LDT
   uint8_t  zero;            // unused, set to 0. reserved
   uint8_t  type_attributes; // gate type, dpl, and p fields
   uint16_t offset_2;        // offset bits 16..31
} __atribute__((packed));

struct idtr {
	uint16_t limit;
	uint32_t base;
} __atribute__((packed));

static struct InterruptDescriptor32 idt[255];

void load_idt() {
	struct idtr idtr;
	idtr.base = (uint32_t) &idt;
	idtr.limit = sizeof(idt) - 1;

	idt_flush();
}





