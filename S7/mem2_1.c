#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

#define REGION_SIZE		4096

int *p;
void  fsecv(int s) {
    char buff[256];					
	sprintf( buff, "segf\n");
	write(1, buff, strlen(buff));	
    exit(0);
}

int main(int argc, char *argv[])
{
	signal(SIGSEGV, fsecv);
    char buff[256];					
    
	sprintf( buff, "Addresses:\n");
	write(1, buff, strlen(buff));	
	sprintf( buff, "\tp: %p\n", &p);
	write(1, buff, strlen(buff));	

	*p = 5;

	sprintf( buff, "\tp Address: %p, p value: %p, *p: %d\n", &p, p, *p);
	write(1, buff, strlen(buff));	

	exit(0);

}