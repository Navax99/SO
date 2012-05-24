#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTRING	256

int main() {
    int socketFD;
    int connectionFD;
    char buffer[MAXSTRING];
    int ret;

    socketFD = createSocket ("lserv");
    if (socketFD < 0)
    {
        perror ("Error creating socket\n");
        exit (1);
    }

    connectionFD = serverConnection (socketFD);
    if (connectionFD < 0)
    {
        perror ("Error establishing connection \n");
        exit (1);
    }

    int fd;
    char c;
    char buff[80];
    ret = read(1, buff, 80);
    while (ret > 0) {
        ret = write (connectionFD, buff, ret);
        if (ret < 0) {
            perror ("Error writing on connection \n");
            exit (1);
        }
        ret = read(1, buff, 80);
    }

    closeConnection (connectionFD);
    deleteSocket (socketFD, "lserv");
}
