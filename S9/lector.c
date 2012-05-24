#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main() {
    int fd;
    char c;
    fd = open("pipe", O_RDONLY);
    while (read(fd, &c, 1)) write(1, &c, 1);
    close(fd);
}
