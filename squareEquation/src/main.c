//! \file "main.c"

//-----------------------------------------------------------------------------------------------
//! This program solves a square equation a*x^2 + b*x + c = 0
//! 
//! HSE, Basic Department "System programming" 
//! Of the Ivannikov Institute of system programming of the Russian Academy of Sciences (ISP RAS)
//!
//! (c) Zykov Mikhail, group БПИ182
//! Data: 08.09.2020
//-----------------------------------------------------------------------------------------------

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//-----------------------------------------------------------------------------------------------

#include "output.c"
#include "solveEquation.c"

//-----------------------------------------------------------------------------------------------

int main()
{
    
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    int option;

    printf("# Welcome to quadratique equation solver!\n");
    printf("Add a, b, c:\n");

    if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
    {
        printf("ERROR: wrong input!\n");
        return -1;
    }

    option = solveQuadratiqueEquation(a, b, c, &x1, &x2);

    printAnswer(option, x1, x2);

}
