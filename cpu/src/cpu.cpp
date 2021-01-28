#include "cpu.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


cpu_struct *CPU(uint32_t StackSize)
{
    cpu_struct *working_cpu = (cpu_struct *)calloc(1, sizeof(cpu_struct));
    if (working_cpu == NULL)
    {
        return NULL;
    }

    working_cpu->ProgramCounter = 0;

    working_cpu->RAM = (Cell *)calloc(limitSizeRAM, sizeof(Cell));

    working_cpu->CPUStack = Stack(StackSize);

    working_cpu->CPURegister = (Cell *)calloc(numberOfRegs, sizeof(uint32_t));

    return working_cpu;
}

int desCPU(cpu_struct *Processor)
{
    free(Processor->CPURegister);
    Processor->CPURegister = NULL;

    free(Processor->RAM);
    Processor->RAM = NULL;

    desStack(Processor->CPUStack);
    free(Processor);


    return 0;
}

int readCode(cpu_struct *Processor, const char *File)
{
    FILE *FileProgram = fopen(File, "rb");
    if (FileProgram == NULL)
    {
        return -1;
    }

    fread(Processor->RAM, sizeof(Cell), sizeOfInput, FileProgram);
    fclose(FileProgram);
    Processor->ProgramCounter = 0;

    return 0;
}

int executeCode(cpu_struct *Processor, uint16_t Command)
{
    switch (Processor->RAM[Processor->ProgramCounter])
    {
        case ADD:
        {
            printf("ADD \n");
            ++Processor->ProgramCounter;
            uint16_t Reg1 = Processor->RAM[Processor->ProgramCounter];

            ++Processor->ProgramCounter;
            uint16_t Reg2 = Processor->RAM[Processor->ProgramCounter];

            Processor->CPURegister[Reg1] = Processor->CPURegister[Reg1] +
                                            Processor->CPURegister[Reg2];

            break;
        }
        case SUB:
        {
            printf("SUB \n");
            ++Processor->ProgramCounter;
            uint16_t Reg1 = Processor->RAM[Processor->ProgramCounter];

            ++Processor->ProgramCounter;
            uint16_t Reg2 = Processor->RAM[Processor->ProgramCounter];

            Processor->CPURegister[Reg1] = Processor->CPURegister[Reg1] -
                                            Processor->CPURegister[Reg2];
            break;
        }
        case DIV:
        {
            printf("DIV \n");
            ++Processor->ProgramCounter;
            uint16_t Reg1 = Processor->RAM[Processor->ProgramCounter];

            ++Processor->ProgramCounter;
            uint16_t Reg2 = Processor->RAM[Processor->ProgramCounter];

            if (Processor->CPURegister[Reg2] == 0)
            {
                return -1;
            }
            Processor->CPURegister[Reg1] = Processor->CPURegister[Reg1] /
                                            Processor->CPURegister[Reg2];
            break;
        }
        case MUL:
        {
            printf("MUL \n");
            ++Processor->ProgramCounter;
            uint16_t Reg1 = Processor->RAM[Processor->ProgramCounter];

            ++Processor->ProgramCounter;
            uint16_t Reg2 = Processor->RAM[Processor->ProgramCounter];

            Processor->CPURegister[Reg1] = Processor->CPURegister[Reg1] *
                                            Processor->CPURegister[Reg2];
            break;
        }
        case MOV:
        {
            printf("MOV \n");
            ++Processor->ProgramCounter;
            uint16_t Reg1 = Processor->RAM[Processor->ProgramCounter];

            ++Processor->ProgramCounter;
            uint16_t Reg2 = Processor->RAM[Processor->ProgramCounter];

            Processor->CPURegister[Reg1] = Processor->CPURegister[Reg2];

            break;
        }
        case POP:
        {
            printf("POP \n");
            ++Processor->ProgramCounter;
            uint16_t Reg1 = Processor->RAM[Processor->ProgramCounter];

            uint16_t num = pop(Processor->CPUStack);

            if (num == -1)
            {
                return -1;
            }
            
            Processor->CPURegister[Reg1] = num;

            break;
        }
        case PUSH:
        {
            printf("PUSH \n");
            ++Processor->ProgramCounter;
            uint16_t Reg1 = Processor->RAM[Processor->ProgramCounter];
            
            if (push(Processor->CPUStack, (Processor->CPURegister[Reg1])) == -1)
            {
                return -1;
            };

            break;
        }
        case CALL:
        {
            printf("CALL \n");
            ++Processor->ProgramCounter;
            uint16_t CallAdress = Processor->RAM[Processor->ProgramCounter];

            if (push(Processor->CPUStack, (Processor->ProgramCounter + 1)) == -1)
            {
                return -1;
            };

            Processor->ProgramCounter = CallAdress - 2;
            break;
        }
        case OUT:
        {
            printf("OUT \n");
            ++Processor->ProgramCounter;
            uint16_t Reg1 = Processor->RAM[Processor->ProgramCounter];

            printf("VALUE: %u\n", Processor->CPURegister[Reg1]);
            break;
        }
        case END:
        {
            printf("END \n");
            
            return END;
        }
        case SET:
        {
            printf("SET \n");
            ++Processor->ProgramCounter;
            uint16_t Reg = Processor->RAM[Processor->ProgramCounter];

            ++Processor->ProgramCounter;
            uint16_t value = Processor->RAM[Processor->ProgramCounter];

            Processor->CPURegister[Reg] = value;
        }
    }

    if (Processor->RAM[Processor->ProgramCounter] == -1)
    {
        printf("ERROR!\n");
        return END;
    }
    return 0;
}
