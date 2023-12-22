#include "cpu.h"

void main() {
	gdt_load();
	idt_load();
}
