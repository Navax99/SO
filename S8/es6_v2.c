#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

char error=0;
void handler(int s) {
    error = 1;
    // char *b = "interrupcion\n";
    //write(1, b, strlen(b));
}

main(){
	char c[80];
    int pid, err;
    char buff[80];
    error = 0;
    signal(SIGINT, handler);
    siginterrupt(SIGINT, 1);
    pid = getpid();
    //kill(pid, SIGINT);
	err = read(0, &c, 80);
    if (errno == 4) sprintf(buff, "error while read%d\n", errno);
    else if (errno != 4) sprintf(buff, "interruption while read\n", errno);
    else  sprintf(buff, "just read\n");
    write(1, buff, strlen(buff));
	write(1, &c, strlen(c));

}
