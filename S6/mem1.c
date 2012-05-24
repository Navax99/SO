#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_ITERATIONS 	100
#define REGION_SIZE		4096

char globalArray[REGION_SIZE];

int
main (int argc, char *argv[])
{

  int niterations = DEFAULT_ITERATIONS;
  int i;
  char localArray[REGION_SIZE];
  char *p;

  if (argc > 2)
    {
      fprintf (stdout, "Usage: mem1 [numMallocs]\n");
      exit (1);
    }

  if (argc == 2)
    {
      niterations = atoi (argv[1]);
    }

  fprintf (stdout, "Addresses:\n");
  fprintf (stdout, "\tglobalArray: %p\n", globalArray);
  fprintf (stdout, "\tlocalArray: %p\n", localArray);
  fprintf (stdout, "\tp: %p\n", &p);


  for (i = 0; i < niterations; i++)
    {
      p = (char *)sbrk(REGION_SIZE);
      fprintf (stdout, "\tp: %p, region %d: %p\n", &p, i, p);
      p = (char *)sbrk(-REGION_SIZE);
    }

  while (1);

}
