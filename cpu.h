#ifndef CPU_H
#define CPU_H

#include"memory.h"
#include<stdint.h>

typedef struct instruction_t
{

}instruction_t;

typedef struct cpu_t
{
	uint8_t reg_a;
	uint8_t reg_x;
	uint8_t reg_y;

	uint8_t reg_p;
	uint8_t reg_sp;
	uint16_t reg_pc;

	int cycles;
	uint8_t opcode;
}cpu_t;

cpu_t* cpu_create();
void cpu_reset(cpu_t* cpu);
void cpu_execute(cpu_t* cpu, memory_t* memory);
void cpu_irq();
void cpu_nmi();
void cpu_tick();
void cpu_close(cpu_t* cpu);

/* operations */
void o_push(cpu_t* cpu, memory_t* memory, uint8_t element);
void o_pop(cpu_t* cpu, memory_t* memory);
void o_set_flag(cpu_t* cpu);


/* addressing modes */
void m_abs(cpu_t* cpu);
void m_abx(cpu_t* cpu);
void m_aby(cpu_t* cpu);
void m_imp(cpu_t* cpu);
void m_imm(cpu_t* cpu);
void m_ind(cpu_t* cpu);
void m_izx(cpu_t* cpu);
void m_izy(cpu_t* cpu);
void m_rel(cpu_t* cpu);
void m_zp(cpu_t* cpu);
void m_zpx(cpu_t* cpu);
void m_zpy(cpu_t* cpu);

/* instructions */
void i_brk(cpu_t* cpu);
void i_ora(cpu_t* cpu);

#endif