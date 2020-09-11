//! \file "calculate.c"

//---------------------------------------------------------------------------------------------------------
//! calculateDiscriminant method calculate the value of discriminant.
//! 
//! @param [in] a - a-coefficient
//! @param [in] b - b-coefficient
//! @param [in] c - c-coefficient
//!
//! @return value of discriminant
//!
//---------------------------------------------------------------------------------------------------------

double calculateDiscriminant(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

//---------------------------------------------------------------------------------------------------------
//! calculateRoots method find roots of equation.
//! 
//! @param [in] discriminantValue - discriminant of equation
//! @param [in] a - a-coefficient
//! @param [in] b - b-coefficient
//! @param [in] c - c-coefficient
//! @param [out] x1 - Pointer to the first root
//! @param [out] x2 - Pointer to the second root
//!
//! @return number of roots
//!
//---------------------------------------------------------------------------------------------------------

double calculateRoots(double discriminantValue, double a, double b, double c, double *x1, double *x2)
{
    if (discriminantValue == 0)
    {
        *x1 = (-1) * b / (2 * a);
        return 1;
    }

    *x1 = ((-1) * b + sqrt(discriminantValue)) / (2 * a);
    *x2 = ((-1) * b - sqrt(discriminantValue)) / (2 * a);
    return 2;
}
