#include "cpu.h";
#include "stdint.h";

struct gdtr {
	uint16_t limit;
	uint32_t base;
} __atribute__((packed));


//why is this such a mess. I mean come on how was it easier to seperate the base and limit into parts.
struct gdt_desc {
	uint16_t limit;
	uint16_t base;
	uint8_t base2;
	uint8_t access;
	uint8_t flags_limit2;
	uint8_t base3;
} __atribute__((packed));

typedef struct gdt_desc gdt_desc;

//I hated writing this and it is pain and I hope I dont need to touch this. 
void load_gdt() {
	gdt_desc gdt[3];

	gdt[0].base = 0;
	gdt[0].limit = 0;
	gdt[0].base2 = 0;
	gdt[0].access = 0;
	gdt[0].flags_limit2 = 0;
	gdt[0].base3 = 0;

	gdt[1].base = 0;
	gdt[1].limit = 0xFFFF;
	gdt[1].base2 = 0;
	gdt[1].access = 0b10011111;
	gdt[1].flags_limit2 = 0b01001111;
	gdt[1].base3 = 0x0;

	gdt[2].base = 0;
	gdt[2].limit = 0xFFFF;
	gdt[2].base2 = 0;
	gdt[2].access = 0b10010111;
	gdt[2].flags_limit2 = 0b01001111;
	gdt[2].base3 = 0;


	struct gdtr gdtr;
	gdtr.base = (uint32_t) &gdt;
	gdtr.limit = sizeof(gdt);

	gdt_flush(gdtr);

}


