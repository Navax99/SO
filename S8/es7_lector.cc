#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
main(){
    char buffer[80];

    int ret = 0;
    read(0,&ret,sizeof(ret));
    sprintf(buffer, "%d\n",ret);
    write(1, &buffer, strlen(buffer));

}
