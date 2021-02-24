#include"nes.h"
//#include"cpu.h"
//#include"memory.h"
#include<stdio.h>

int main(int argc, char** argv)
{
	nes_t* nes = nes_create();
	nes_run(nes);
	nes_close(nes);
}