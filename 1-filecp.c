#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void func()
{
    int fd1, fd2;
    fd1 = open("../fd1.txt", O_RDONLY);
    fd2 = open("../fd2.txt", O_RDWR|O_CREAT, 0600);

	if (fd1 < 0) {
        printf("fd1 can not be read!\n");
        return;
    }
    if (fd2 < 0) {
        printf("fd2 can not be write!\n");
        return;
    }

    char buffer[2];

    while (read(fd1, buffer, 1))
        write(fd2, buffer, 1);
}