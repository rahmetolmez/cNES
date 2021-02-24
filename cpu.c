#include"cpu.h"
#include<stdlib.h>

cpu_t* cpu_create()
{
	cpu_t* cpu = malloc(sizeof(cpu_t));
	cpu_reset(cpu);
	return cpu;
}

void cpu_reset(cpu_t* cpu)
{
	cpu->reg_a = 0x00;
	cpu->reg_x = 0x00;
	cpu->reg_y = 0x00;

	cpu->reg_p = 0x00;
	cpu->reg_sp = 0x00;
	cpu->reg_pc = 0x0000;
}

void cpu_execute(cpu_t* cpu, memory_t* memory)
{
	
	cpu->opcode = memory_read(memory, cpu->reg_pc);
	//cpu->cycles = instruction_table[opcode];
	switch(cpu->opcode)
	{
		case 0x00:
			i_brk(cpu);
			break;
		case 0x01:
			m_izx(cpu);
			i_ora(cpu);
			break;
		case 0x05:
			m_zp(cpu);
			i_ora(cpu);
			break;
		default:
			return;
	}
}

void cpu_close(cpu_t* cpu)
{
	free(cpu);
}

/* operations */
void o_push(cpu_t* cpu, memory_t* memory, uint8_t element)
{
	/*memory->ram[cpu->reg_sp] = element;*/
	cpu->reg_sp--;
}

void o_pop(cpu_t* cpu, memory_t* memory)
{

}

void o_set_flag(cpu_t* cpu, char flag, uint8_t value)
{
	if(value == 1)
		switch(flag)
		{
			case 'C':
				cpu->reg_p = cpu->reg_p | 0x01;
				break;
			case 'Z':
				cpu->reg_p = cpu->reg_p | 0x02;
				break;
			case 'I':
				cpu->reg_p = cpu->reg_p | 0x04;
				break;
			case 'D':
				cpu->reg_p = cpu->reg_p | 0x08;
				break;
			case 'V':
				cpu->reg_p = cpu->reg_p | 0x40;
				break;
			case 'N':
				cpu->reg_p = cpu->reg_p | 0x80;
				break;	
		}
	else if(value == 0)
		switch(flag)
		{
			case 'C':
				cpu->reg_p = cpu->reg_p & ~0x01;
				break;
			case 'Z':
				cpu->reg_p = cpu->reg_p & ~0x02;
				break;
			case 'I':
				cpu->reg_p = cpu->reg_p & ~0x04;
				break;
			case 'D':
				cpu->reg_p = cpu->reg_p & ~0x08;
				break;
			case 'V':
				cpu->reg_p = cpu->reg_p & ~0x40;
				break;
			case 'N':
				cpu->reg_p = cpu->reg_p & ~0x80;
				break;	
		}
}

/* addressing modes */
void m_abs(cpu_t* cpu)
{

}

void m_abx(cpu_t* cpu)
{

}

void m_aby(cpu_t* cpu)
{

}

void m_imp(cpu_t* cpu)
{

}

void m_imm(cpu_t* cpu)
{

}

void m_ind(cpu_t* cpu)
{

}

void m_izx(cpu_t* cpu)
{

}

void m_izy(cpu_t* cpu)
{

}

void m_rel(cpu_t* cpu)
{

}

void m_zp(cpu_t* cpu)
{

}

void m_zpx(cpu_t* cpu)
{

}

void m_zpy(cpu_t* cpu)
{

}

/* instructions */
void i_brk(cpu_t* cpu)
{
	/*o_push(cpu, cpu->reg_pc);
	o_push(cpu, cpu->reg_p);*/
}

void i_ora(cpu_t* cpu, memory_t* memory)
{
	/*cpu->reg_a = cpu->reg_a | memory_read(cpu->pc);*/

	o_set_flag(cpu, 'Z', (cpu->reg_a == 0x00));
	o_set_flag(cpu, 'N', ((cpu->reg_a >> 7) == 1));
}