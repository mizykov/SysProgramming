#include <unistd.h>

struct Line
{
    int fd;
    int offset;
    int size;
    int original_position;
};

void readStr(int fd, int off, int size, char *buff)
{
    lseek(fd, off, SEEK_SET);
    read(fd, buff, size);
}