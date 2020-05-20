#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argn,char **argv){
    char *fileName = argv[1];
    char buffer;
    char espacio = 0;
    unsigned int c = 0, l = 0, w = 0;
    int fd = open(fileName, O_RDONLY);
    if(fd<0) {
        printf("No se puede abrir \n");
        exit(1);
    }
    while(read(fd,&buffer,1)){
        c += 1;
        if(buffer == '\n') l += 1;
        if((buffer == ' ' || buffer == '\n' || buffer == EOF) && espacio == 0){
            espacio = 1;
            w += 1;
        } else if(buffer != ' ' && buffer != '\n' && buffer != EOF){
            espacio = 0;
        }
    }
    printf("%d %d \n",l,c);
    close(fd);
    exit(0);
}