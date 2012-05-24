#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTRING	256

int main() {
    char c;
    int connectionFD;
    int ret;
    char buffer[MAXSTRING];

    connectionFD = clientConnection ("lserv");
    if (connectionFD < 0)
    {
        perror ("Error establishing connection\n");
        exit (1);
    }
    ret = read (connectionFD, buffer, sizeof (buffer));
    if (ret < 0)
    {
        perror ("Error reading from connection\n");
        exit (1);
    }

    while (ret > 0) {
        write(1, &buffer, ret);
        ret = read (connectionFD, buffer, sizeof (buffer));
        if (ret < 0)
        {
            perror ("Error reading from connection\n");
            exit (1);
        }

    }
    closeConnection (connectionFD);
}
