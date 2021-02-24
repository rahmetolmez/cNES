#ifndef MEMORY_H
#define MEMORY_H

#include<stdint.h>

#define RAM_SIZE 65536

typedef struct memory_t
{
	uint8_t ram[RAM_SIZE];
	int size;
}memory_t;

memory_t* memory_create();
void memory_clear(memory_t* memory);
uint8_t memory_read(memory_t* memory, uint16_t address);
void memory_write(memory_t* memory, uint16_t address, uint8_t data);
void memory_close(memory_t* memory);

#endif