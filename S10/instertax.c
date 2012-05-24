       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
 #include <unistd.h>

int main() {
    int fd;
    fd = open("salida.txt", O_RDWR, S_IRWXU);
    lseek(fd, -1, SEEK_END);
    char buff;
    read(fd, &buff, 1);
    lseek(fd, -1, SEEK_END);
    write(fd, "X", 1);
    lseek(fd, 0, SEEK_END);
    write(fd, &buff, 1);

    //write(fd, &buff, 1);
    close(fd);
}
