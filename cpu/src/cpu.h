#include "stdint.h"
#include "stack.h"

extern uint32_t limitSizeRAM;

const uint8_t numberOfRegs = 32;
const uint16_t sizeOfInput = 20;

// ERRORS for logging in interface
enum errors
{
    E1,
    E2,
    E3,
    E4,
    E5,
    E6,
    E7
};

typedef uint32_t Cell;

enum commands
{
    ADD, // ADD A B - add B to A and write in register A
    SUB, // SUB A B - sub B from A and write in register A
    DIV, // DIV A B - div A on B and write in register A
    MUL, // MUL A B - mul A on B and write to register A
    MOV, // MOV A B - move value of register B to register A
    POP, // POP X - take register X from stack for executing
    PUSH, // PUSH X - set register X in stack for executing
    CALL, // CALL X - call other function with address X
    OUT, // OUT X - print value in register X
    END, // end of working
    SET, // SET A B - set value B in register A
};

// struct of cpu
typedef struct
{
    uint32_t ProgramCounter;
    my_stack *CPUStack;
    Cell *RAM;
    uint32_t *CPURegister;
} cpu_struct;

cpu_struct *CPU(uint32_t StackSize);

int desCPU(cpu_struct *Processor);

int readCode(cpu_struct *Processor, const char *File);

int executeCode(cpu_struct *Processor, uint16_t Command);
