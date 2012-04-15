#include<stdio.h>
#include<stdlib.h>

void
suma (int op1, int op2, int *res)
{
  *res = op1 + op2;
}

int j;

int
main (int argc, char *argv[])
{
  int i;
  int s;

  if (argc != 3)
    {
      fprintf (stdout, "Usage: %s num1 num2\n", argv[0]);
      exit (1);
    }

  i = atoi (argv[1]);
  j = atoi (argv[2]);
  suma (i, j, &s);
  fprintf (stdout, "suma de %d y %d es %d\n", i, j, s);

  exit (0);
}
