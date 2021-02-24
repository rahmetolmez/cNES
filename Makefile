all:
	gcc -o main main.c cpu.c memory.c nes.c cartridge.c -g -Wall

run:
	./main

test:
	gcc -o tests/test tests/test_cpu.c cpu.c memory.c nes.c cartridge.c -g -Wall && ./tests/test