#include <fcntl.h>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <iostream>
#include "stdlib.h"

#include "utils.cpp"
#include "comparators.cpp"
#include "sort.cpp"

int main(int argc, char **argv)
{
    /** FILE *normal_out = fopen(argv[2], "w"),
         *sorted_out = fopen(argv[3], "w"),
         *reversed_sorted_out = fopen(argv[4], "w"); **/

    char *path = "input.txt";
    int fd = open(path, O_RDWR);

    char buffer[5];
    Line lines[100];

    lines[0].offset = 0;
    int strings_number = 1;
    int off = 0;
    int current_size = 0;

    while (true)
    {
        ssize_t s = read(fd, buffer, 1);
        ++off;
        ++current_size;

        if (s == 0)
        {
            break;
        }
        else if (buffer[0] == '\n')
        {
            lines[strings_number - 1].size = current_size - 2;
            lines[strings_number - 1].fd = fd;
            lines[strings_number - 1].original_position = strings_number - 1;
            current_size = 0;
            lines[strings_number].offset = off;
            strings_number++;
        }
    }

    for (int i = 0; i < strings_number; ++i)
    {
        printf("off: %d \n", lines[i].offset);
    }

    for (int i = 0; i < strings_number; ++i)
    {
        printf("size: %d \n", lines[i].size);
    }

    // Original
    for (int i = 0; i < strings_number; ++i)
    {
        char *b = new char[lines[i].size];
        readStr(fd, lines[i].offset, lines[i].size, b);
        printf("%s\n", b);
        delete b;
    }

    // Direct sort
    Line *an = bubbleSort(strings_number, lines, direct_compare);

    for (int i = 0; i < strings_number; ++i)
    {
        char *b = new char[an[i].size];
        readStr(fd, an[i].offset, an[i].size, b);
        printf("%s\n", b);
        delete b;
    }

    // Reverse sort
    an = bubbleSort(strings_number, lines, direct_compare);

    for (int i = 0; i < strings_number; ++i)
    {
        char *b = new char[an[i].size];
        readStr(fd, an[i].offset, an[i].size, b);
        printf("%s\n", b);
        delete b;
    }

    /** fclose(normal_out);
    fclose(sorted_out);
    fclose(reversed_sorted_out); **/

    close(fd);

    return 0;
}
