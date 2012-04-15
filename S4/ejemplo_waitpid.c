#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc,char *argv[])
{
	char buff[256];		
	int pid,res;
	int hijos=0;
	for (hijos=0;hijos<10;hijos++)
	{
		sprintf( buff,  "Creando el hijo numero %d\n", hijos);
		write(1, buff, strlen(buff)); 
		pid=fork();
		if (pid==0) /* Esta linea la ejecutan tanto el padre como el hijo */
		{
			/* Escribe aqui el codigo del proceso hijo */
			sprintf( buff, "Hola, soy %d\n",getpid());
			write(1, buff, strlen(buff)); 
			/* Termina su ejecución */
			exit(0);
		}else if (pid<0)	
		{
			/* Se ha producido un error */
			perror("Error en el fork");
		}
	}
	/* Esperamos que acaben los hijos */
	for (hijos=0;hijos<10;hijos++)
	{
		pid=waitpid(-1,&res,0);
		sprintf( buff, "Termina el proceso %d\n",pid);
		write(1, buff, strlen(buff)); 
	}
	return 0;
}
