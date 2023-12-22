#include <stdint.h>

struct cpu_ctx {
	uint32_t EAX;
	uint32_t ECX;
	uint32_t EDX;
	uint32_t EBX;
	uint32_t ESP;
	uint32_t EBP;
	uint32_t ESI;
	uint32_t EDI;
};

void load_gdt();
void load_idt();

//TODO: get interupts working. figure out userland
