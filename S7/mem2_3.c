#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>


#define REGION_SIZE 256

/*
 * rddtsc is an assembler instruction that get the cycles executed by the processor since boot time.
 */
#define getCycles(low,high) __asm__ __volatile__("rdtsc": "=a"(low), "=d"(high))

static inline unsigned long long getTime(void)
{
	unsigned long low, high;
	getCycles(low, high);
	return ((unsigned long long)high << 32) + low;

}

/*
 * main
 */
int main(int argc, char **argv)
{
	int i;
	int *p;
	int nregions;
	short freeRegion = 0;
	unsigned long long initTime;
	unsigned long long endTime;
	struct rusage init;
	struct rusage end;
	char buff[256];					

	if ((argc != 2) && (argc != 3)) {
		sprintf( buff, "usage: mem2_3 nregions [0|1]\n");
		write(1, buff, strlen(buff));	
		exit(1);
	}
	nregions = atoi(argv[1]);

	if (argc == 3)
		freeRegion = atoi(argv[2]);

	for (i = 0; i < nregions; i++) {
		initTime = getTime();
		getrusage( RUSAGE_SELF, &init );
		p = malloc(REGION_SIZE * sizeof(int));
		if (p == NULL) {
			sprintf( buff, "Unable to allocate region %d\n", i);
			write(1, buff, strlen(buff));	
			exit(1);
		}
		getrusage( RUSAGE_SELF, &end );
		endTime = getTime();
		if (freeRegion)
			free(p);
		sprintf( buff, "iteration %d, malloc time: %llu minor page faults = %ld\n", 
				i, endTime - initTime, end.ru_minflt - init.ru_minflt);
		write(1, buff, strlen(buff));	

	}

	exit(0);
}
