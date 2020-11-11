#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
   

    int fd = open("./lee.c", O_RDONLY, 0);
    if(fd <0){
        printf("error al abrir archivo \n");
        return 1;
    }
    
    char c;
    while(read(fd,&c,1)){
        printf("%c", c);
    }

    
    return 0;
}