#include <fcntl.h>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "stdlib.h"


#include "utils.cpp"
#include "comparators.cpp"
#include "sort.cpp"


int main(int argc, char **argv)
{
        std::ofstream original_out, sorted_out, reverse_sorted_out;
        original_out.open(argv[2]);
        sorted_out.open(argv[3]);
        reverse_sorted_out.open(argv[4]);

        char *path = argv[1];
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
                        break;
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

        // Original
        for (int i = 0; i < strings_number - 1; ++i)
        {
                char *b = new char[lines[i].size];
                readStr(fd, lines[i].offset, lines[i].size, b);
                for (size_t j = 0; j < lines[i].size; j++, b++)
                        original_out << *b;
                original_out << "\n";
                b = (b - lines[i].size);
                delete b;
        }

        // // Direct sort
        Line *an = bubbleSort(strings_number - 1, lines, direct_compare);

        for (int i = 0; i < strings_number - 1; ++i)
        {
                char *b = new char[an[i].size];
                readStr(fd, an[i].offset, an[i].size, b);
                for (size_t j = 0; j < lines[i].size; j++, b++)
                        sorted_out << *b;
                sorted_out << "\n";
                b = (b - lines[i].size);
                delete b;
            }

        // // Reverse sort
        an = bubbleSort(strings_number - 1, lines, reverse_compare);

        for (int i = 1; i < strings_number - 1; ++i)
        {
                char *b = new char[an[i].size];
                readStr(fd, an[i].offset, an[i].size, b);
                for (size_t j = 0; j < lines[i].size; j++, b++)
                        reverse_sorted_out << *b;
                reverse_sorted_out << "\n";
                b = (b - lines[i].size);
                delete b;
        }

        original_out.close();
        sorted_out.close();
        reverse_sorted_out.close();

        close(fd);

        return 0;
}
