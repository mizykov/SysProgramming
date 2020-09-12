//! \file "output.c"

//-----------------------------------------------------------------------------
//! printAnswer method print message to terminal.
//!
//! @param [in] option - number of roots
//! @param [in] x1 - first root
//! @param [in] x2 - second root
//!
//! @return message to terminal
//!
//-----------------------------------------------------------------------------

void printAnswer(int option, double x1, double x2)
{
        switch (option) {
        case -1:
                printf("Infinite number of solutions\n");
                break;
        case 0:
                printf("No roots\n");
                break;
        case 1:
                printf("x = %.4lg\n", x1);
                break;
        case 2:
                printf("x1 = %.4lg, x2 = %.4lg\n", x1, x2);
                break;
        }
}