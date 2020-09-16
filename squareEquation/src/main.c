//! \file "main.c"

//-----------------------------------------------------------------------------
//! This program solves a square equation a*x^2 + b*x + c = 0
//! 
//! HSE, Basic Department "System programming" 
//! Of the Ivannikov Institute of system programming of 
//! the Russian Academy of Sciences (ISP RAS)
//!
//! (c) Zykov Mikhail, group БПИ182
//! Data: 08.09.2020
//-----------------------------------------------------------------------------

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//-----------------------------------------------------------------------------

#include "output.c"
#include "solveEquation.c"

//-----------------------------------------------------------------------------

const int MAX_VALUE = 2147483647;

//-----------------------------------------------------------------------------

int main()
{
    
        double a = 0.0, b = 0.0, c = 0.0;
        double x1 = 0.0, x2 = 0.0;
        int option;

        printf("# Welcome to quadratique equation solver!\n");
        printf("# Attention: maximum value of the coefficient is 2.147.483.647 (MAX_INTEGER)\n");
        printf("#            coefficients and roots are real numbers with accuracy = 1E-6\n");
        printf("Add a, b, c:\n");

        if (scanf("%lf %lf %lf", &a, &b, &c) != 3 || 
                (fabs(a) > MAX_VALUE) || 
                (fabs(b) > MAX_VALUE) || 
                (fabs(c) > MAX_VALUE)) {
                printf("ERROR: wrong input!\n");
                return -1;
        }

        option = solveQuadratiqueEquation(a, b, c, &x1, &x2);

        printAnswer(option, x1, x2);

}
