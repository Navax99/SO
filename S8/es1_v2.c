#include <unistd.h>
#include <string.h>

main(){
    char *buf="fin ejecución\n";
    int ret;
    char buf2[256];
    ret=read(0,&buf2,sizeof(buf2));
    while(ret>0){
        write(1,&buf2,ret);
        ret=read(0,&buf2,sizeof(buf2));
    }
    write(1,buf,strlen(buf));
}
