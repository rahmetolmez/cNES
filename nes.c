/*
 * NES Emulator
 *
 * Author: Rahmet Ali Ölmez
 * February 2020
 *
 * +------+----------------------------------------+
 * |      | Nintendo                    ||||||||   |
 * |      | Entertainment System        ||||||||   |
 * |      +-----------------------------||||||||   |
 * |                                    ||||||||   |
 * |                                    ||||||||   |
 * | +-----+  +-----+                   ||||||||   |
 * | +-----+  +-----+                   ||:||:||   |
 *  \                                   ||||||||  /
 *   +-------------------------------------------+
 */

/*   +--------------------------------------------------------------+
     | +----------------------------------------------------------+ |
     | |                   +----------------+                     | |
     | |                                                          | |
     | |                   +----------------+      Nintendo       | |
     | |                   +----------------+                     | |
     | |        +-+                                               | |
     | |        | |        +----------------+                     | |
     | |    +---- ----+    |SELECT    START |                     | |
     | |    +---- ----+    +----------------+     +---+ +---+     | |
     | |        | |        | |---|    |---| |     | O | | O |     | |
     | |        +-+        +----------------+     +---+ +---+     | |
     | |                                              B     A     | |
     | |                   +----------------+                     | |
     | +----------------------------------------------------------+ |
     +--------------------------------------------------------------+
*/

#include"nes.h"
#include"cpu.h"
#include"memory.h"
#include<stdlib.h>
#include<stdio.h>

nes_t* nes_create()
{
	nes_t* nes = malloc(sizeof(nes_t));
	nes->cpu = cpu_create();
	nes->memory = memory_create();

	nes_reset(nes);
	return nes;
}

void nes_reset(nes_t* nes)
{
	cpu_reset(nes->cpu);
	memory_clear(nes->memory);
}

void nes_load_cartridge(nes_t* nes, const char* file_path)
{

}

void nes_run(nes_t* nes)
{
	memory_write(nes->memory, nes->cpu->reg_pc, 0xaf);
	printf("ram at pc: 0x%x\n", memory_read(nes->memory, nes->cpu->reg_pc));
	printf("pc: 0x%x\n", nes->cpu->reg_pc);

	cpu_execute(nes->cpu, nes->memory);
}

void nes_close(nes_t* nes)
{
	cpu_close(nes->cpu);
	memory_close(nes->memory);
	free(nes);
}