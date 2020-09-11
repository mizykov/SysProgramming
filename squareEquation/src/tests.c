#include "testLibrary.c"

int main()
{
    okTwoRoots(2, 4, -1, 1, -3, -4);
    okTwoRoots(2, 4, -4, 4, 0, -64);
    okTwoRoots(2, 1, -3, 1, 2, -3);
    okTwoRoots(2, 0.5, -3, 2, 5, -3);

    okOneRoot(1, -3, 1, 6, 9);
    okOneRoot(1, 2, 0, 2, -4);

    okZeroOrInfinityRoots(0, 1, 2, 17);
    okZeroOrInfinityRoots(0, 0, 0, 6);
    okZeroOrInfinityRoots(-1, 0, 0, 0);
}