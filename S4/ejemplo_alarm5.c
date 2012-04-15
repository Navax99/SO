#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int pid;

void trat_alarm(int signum) {

}

int main(int argc,char *argv[])
{
	char buff[256];		
	int ret,res;
	signal(SIGALRM, trat_alarm);
	pid=fork();
	switch(pid) {
		case 0: sprintf( buff, "Hola, soy %d\n",getpid());
			write(1, buff, strlen(buff)); 
			sleep(1);			
			exit(0);
		case -1: 
			perror("Error en el fork");
			exit(1);
	}

	ret=waitpid(-1,&res,0);
	
	sprintf( buff, "Termina el proceso %d\n",pid);
	write(1, buff, strlen(buff)); 

	return 0;
}
