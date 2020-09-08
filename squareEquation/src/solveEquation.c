//---------------------------------------------------------------------------------------------------------
//! solveLinearEquation method find one root.
//! 
//! @param [in] b - b-coefficient
//! @param [in] c - c-coefficient
//! @param [out] x1 - Pointer to the first root
//!
//! @return number of roots
//!
//---------------------------------------------------------------------------------------------------------

int solveLinearEquation(double b, double c, double *x1)
{
    if (b == 0)
    {
        return c == 0 ? -1 : 0;
    }

    *x1 = (-1) * c / b;
    return 1;
}

//---------------------------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------------------------

int solveQuadratiqueEquation(double a, double b, double c, double *x1, double *x2)
{
    double discriminantValue;

    if (a == 0)
    {
        return solveLinearEquation(b, c, x1);
    }

    discriminantValue = calculateDiscriminant(a, b, c);

    if (discriminantValue >= 0)
    {
        return calculateRoots(discriminantValue, a, b, c, x1, x2);
    }

    return 0;
}