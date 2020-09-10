//===============================================================================
//! This program solves a square equation a*x^2 + b*x + c = 0
//! 
//! HSE, Basic Department "System programming" 
//! Of the Ivannikov Institute of system programming of the Russian Academy of Sciences (ISP RAS)
//!
//! (c) Zykov Mikhail, group БПИ182
//! Data: 08.09.2020
//===============================================================================

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//===============================================================================

#include "output.c"
#include "calculate.c"
#include "solveEquation.c"
#include "testing.c"

//===============================================================================

//! is_test - uses for launch a couple of tests.
//! If you want to test it yourself, comment on this line.

#define is_test

//===============================================================================

int main()
{

#ifdef is_test

    okTwoRoots(2, 4, -1, 1, -3, -4);
    okTwoRoots(2, 4, -4, 4, 0, -64);
    okTwoRoots(2, 1, -3, 1, 2, -3);
    okTwoRoots(2, 0.5, -3, 2, 5, -3);

    okOneRoot(1, -3, 1, 6, 9);
    okOneRoot(1, 2, 0, 2, -4);

    okZeroOrInfinityRoots(0, 1, 2, 17);
    okZeroOrInfinityRoots(0, 0, 0, 6);
    okZeroOrInfinityRoots(-1, 0, 0, 0);

#endif

#ifndef is_test

    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    int option;

    printf("# Welcome to quadratique equation solver!\n");
    printf("Add a, b, c:\n");

    if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
    {
        puts("ERROR: wrong input!");
        return -1;
    }

    option = solveQuadratiqueEquation(a, b, c, &x1, &x2);

    printAnswer(option, x1, x2);

#endif

}
