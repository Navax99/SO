#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
void
error (char *msg)
{
  perror (msg);
  exit (0);
}

void
crea_ps ()
{
  int pid;
  pid = fork ();
  if (pid == 0)
    {
      execlp ("ps", "ps", (char *) 0);
      error ("execlp");
    }
  else if (pid < 0)
    error ("fork");
}

void
f_alarma (int s)
{
}

void
main (int argc, char *argv[])
{
  int x;
  x = 0;
  signal (SIGALRM, f_alarma);
  while (x < 100)
    {
      alarm (2);
      pause ();
      crea_ps ();
      x++;
    }
}
