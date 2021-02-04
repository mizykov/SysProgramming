#include "cpu.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int writeCode(cpu_struct *Processor, const char *File)
{
    FILE *FileProgram = fopen(File, "wb");

    if (FileProgram == NULL)
    {
        return -1;
    }

    //
    // 
    //

    return 0;
}
