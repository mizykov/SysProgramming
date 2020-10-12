#include <fcntl.h>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <iostream>
#include "stdlib.h"

#include "utils.cpp"
#include "comparators.cpp"
#include "sort.cpp"

int main()
{
    int arr[] = {1,6,31,3,5,1,7,7,1,7,64};
    int n = 11;

    for (size_t i = 0; i < n; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    int *p = intbubbleSort(n, arr);
    

    for (size_t i = 0; i < n; i++,p++)
    {
        std::cout << *p << ' ';
    }
    std::cout << '\n';


    return 0;
}