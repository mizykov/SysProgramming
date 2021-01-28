#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

#include "cpu.h"

uint32_t stackSize = 50;
uint32_t limitSizeRAM = 1024;


int main(int argc, char *argv[])
{
	cpu_struct *Processor = NULL;
	Processor = CPU(stackSize);
	int command = 0;

	// Read .bin of the program file in RAM.
	if (readCode(Processor, argv[1]) != 0)
	{
		printf("Error reading from file!\n");
		return 0;
	}

	// Program processing cycle.
	while (command != END)
	{
		command = executeCode(Processor, Processor->RAM[Processor->ProgramCounter]);

		if (command == -1)
		{
			command = END;
		}

		// Delay for smooth output of processor command execution logs.
		for (int j = 0; j < 1000000; ++j) {}

		Processor->ProgramCounter++;
	}

	printf("============================================\n");
	printf("The processor has worked out the input code.\n");
	printf("============================================\n");

	return 0;
}
