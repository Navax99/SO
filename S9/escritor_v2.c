#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>


int main() {
    int fd;
    char c[10];
    fd = open("/home/alumne/S9/pipe", O_WRONLY | O_NONBLOCK);
    if (errno == ENXIO) {
        write(1, "No\n", 3);
        while (errno == ENXIO) {
            close(fd);
            fd = open("pipe", O_WRONLY | O_NONBLOCK);
        }
    }
    sprintf(c, "%d fd\n", fd);
    write(1, c, strlen(c));

    write(1, "N\n", 3);
    int ret = read(0, &c, 10);
    while (ret > 0){
        write(fd, c, ret);
        ret = read(0, &c, 10);
    }
    close(fd);
}
