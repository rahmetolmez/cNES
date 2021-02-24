#ifndef NES_H
#define NES_H

#include"cpu.h"
#include"memory.h"

typedef struct nes_t
{
	cpu_t* cpu;
	memory_t* memory;
	//ppu
}nes_t;

nes_t* nes_create();
void nes_reset(nes_t* nes);
void nes_load_cartridge(nes_t* nes, const char* file_path);
void nes_run(nes_t* nes);
void nes_close(nes_t* nes);

#endif