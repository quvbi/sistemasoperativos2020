#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char **argv){
    char sourceFile = argv[1];
    char destinationFile = argv[2];


    int fd = open("./lee.c", O_RDONLY, 0);
    if(fd <0){
        printf("error al abrir archivo \n");
        return 1;
    }
        int fd1 = open(destinationFile, O_WRONLY| O_CREAT, 0600);

    char c;
    while(read(fd,&c,1)){
        printf(fd1, &c, 1);
    }

    close(fd);
    close(fd1);
    return 0;
}