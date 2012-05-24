#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>


int main() {
    int fd;
    char c;
    char buff[80];
    fd = open("pipe", O_WRONLY);
    while (read(1, &c, 1)) write(fd, &c, 1);
    close(fd);
}
