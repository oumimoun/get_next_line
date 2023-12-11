#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int main ()
{
    int fd;
    char buff[10];
    int i = 0;

    fd = open("file.txt", O_RDONLY );
    while ((i = read(fd, buff, 10)))
    {
        printf("|%s|\n", buff);
    }
}
