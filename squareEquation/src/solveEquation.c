//! \file "solveEquation.c"

//-----------------------------------------------------------------------------
//! solveLinearEquation method find one root.
//! 
//! @param [in] b - b-coefficient
//! @param [in] c - c-coefficient
//! @param [out] x1 - Pointer to the first root
//!
//! @return number of roots
//!
//-----------------------------------------------------------------------------

#include "calculate.c"
//-----------------------------------------------------------------------------

int solveLinearEquation(double b, double c, double *x1)
{
        if (isZero(b))
                return isZero(c) ? -1 : 0;

        if (!isZero(c))
                *x1 = (-1) * c / b;

        return 1;
}

//-----------------------------------------------------------------------------
//! solveQuadratiqueEquation method find equation roots.
//! 
//! @param [in] a - a-coefficient
//! @param [in] b - b-coefficient
//! @param [in] c - c-coefficient
//! @param [out] x1 - Pointer to the first root
//! @param [out] x2 - Pointer to the second root
//!
//! @return number of roots
//!
//-----------------------------------------------------------------------------

// TODO: struct for a b c x1 x2, classes wtith .h files

int solveQuadratiqueEquation(double a, double b, double c, 
                             double *x1, double *x2)
{
        double discriminantValue;

        if (isZero(a))
                return solveLinearEquation(b, c, x1);

        discriminantValue = calculateDiscriminant(a, b, c);

        if (isZero(discriminantValue))
                discriminantValue = 0.0;

        if (discriminantValue >= 0)
                return calculateRoots(discriminantValue, a, b, c, x1, x2);

        return 0;
}