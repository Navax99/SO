#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
int alarma=0;
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
	alarma=1;
}
void
fin_hijo (int s)
{
	while (waitpid(-1,NULL,WNOHANG)>0);
}

void
main (int argc, char *argv[])
{
  int x;
  x = 0;
  signal (SIGALRM, f_alarma);
  signal(SIGCHLD,fin_hijo);
  while (x <10)
    {
      alarm (2);
      while (alarma==0) pause ();
      alarma=0;
      crea_ps ();
      x++;
    }
}
