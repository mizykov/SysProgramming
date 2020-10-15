#include <stdio.h>

#include "stack.h"

int main()
{
    int arr[] = {1, 3, 5, 7, 9};
    for (int i = 0; i < 5; i++)
    {
        printf("address_x = %x, value = %d\n", &arr[i], arr[i]);
    }

    printf("\n");

    int arr2[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        printf("address_x = %x, value = %d\n", &arr2[i], arr2[i]);
    }

    printf("-> \n");

    int *a1 = &arr[7];
    int *a2 = &arr[9];
    int *a3 = &arr[11];
    int *a4 = &arr[17];
    int *a5 = &arr[13];

    printf("change this: \n");
    printf("%x\n%x\n%x\n%x\n%x\n", &arr[7], &arr[9], &arr[11], &arr[17], &arr[13]);

    *a1 = 123412;
    *a2 = 12223412;
    *a3 = 123434212;
    *a4 = 423323;
    *a5 = 321;

    printf("Before changes:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("address_x = %x, value = %d\n", &arr2[i], arr2[i]);
    }

    return 0;
}