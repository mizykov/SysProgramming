//! \file "testLibrary.c"

//-----------------------------------------------------------------------------
//! okTwoRoots method compare expected and received answers.
//! 
//! @param [in] expected_option - number of solutions (2: two roots, 
//!                                                    1: one root,
//!                                                    0: no roots,
//!                                                    -1: infinity)
//! @param [in] expected_x1 - expected value of first root
//! @param [in] expected_x2 - expected value of second root
//! @param [in] a - a-coefficient
//! @param [in] b - b-coefficient
//! @param [in] c - c-coefficient
//!
//! @return print result of test
//!
//! @note such methods as okOneRoot and okZeroOrInfinityRoots
//!       use it at their core
//!
//-----------------------------------------------------------------------------

void okTwoRoots(int expected_option, double expected_x1, double expected_x2, 
                double a, double b, double c)
{
        double x1 = 0, x2 = 0;
        int option;
        int testPassed = 1;

        option = solveQuadratiqueEquation(a, b, c, &x1, &x2);

        if (expected_option != option || expected_x1 != x1 || expected_x2 != x2)
                testPassed = 0;

        if (testPassed == 1)
                printf("TEST IS PASSED\n");
        else
                printf("TEST IS FAILED\n");
}

void okOneRoot(int expected_option, double expected_x, 
               double a, double b, double c)
{
        okTwoRoots(expected_option, expected_x, 0, a, b, c);
}

void okZeroOrInfinityRoots(int expected_option, double a, double b, double c)
{
        okTwoRoots(expected_option, 0, 0, a, b, c);
}
