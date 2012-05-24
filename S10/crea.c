       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
 #include <unistd.h>

int main() {
    int fd;
    fd = open("salida.txt", O_CREAT | O_RDWR, S_IRWXU);
    write(fd, "ABCDE", 5);
    close(fd);
}
