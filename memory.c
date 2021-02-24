#include"memory.h"
#include<stdlib.h>
#include<stdio.h>

memory_t* memory_create()
{
	memory_t* memory = malloc(sizeof(memory_t));
	memory->size = RAM_SIZE;
	memory_clear(memory);
	return memory;
}

void memory_clear(memory_t* memory)
{
	for(int i = 0; i < memory->size; i++)
	{
		memory->ram[i] = 0x00;
	}
}

uint8_t memory_read(memory_t* memory, uint16_t address)
{
	if(address < 0x0000 || address >= memory->size)	//equals or not?
	{
		printf("ERROR: READ ADDRESS INVALID");
		return 0x00;
	}
	return memory->ram[address];
}

void memory_write(memory_t* memory, uint16_t address, uint8_t data)
{
	if(address < 0x0000 || address >= memory->size)	//equals or not?
	{
		printf("ERROR: WRITE ADDRESS INVALID");
		return;
	}
	memory->ram[address] = data;
}

void memory_close(memory_t* memory)
{
	free(memory);
}