#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pid, fd[2];
    pipe(fd);
    pid = fork();
    if (pid == 0) {
        close(0); dup(fd[0]);
        close(fd[0]); close(fd[1]);
        execlp("cat","cat", NULL);
    }
    int lol = dup(fd[1]);
    write(5,"INICIO\n", 7);
    close(5);
    close(fd[0]); close(fd[1]);
    int i;
    waitpid(-1,&i, 0);
    write(1, "FIN\n", 4);


}
