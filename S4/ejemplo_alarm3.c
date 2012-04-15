#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

int segundos=0;
void funcio_alarm(int signal)
{
	char buff[256];
	segundos=segundos+10;
	sprintf(buff,"ALARMA: %d segundos\n",segundos);
	write(1, buff, strlen(buff) );
}
int main (int argc,char * argv[])
{
	signal(SIGALRM,funcio_alarm);
	fork();
	while (segundos<100)
	{
		alarm(10);
		pause();
	}
	exit(1);
}
