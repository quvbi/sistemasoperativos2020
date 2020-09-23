#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv){

unsigned pid = fork();
if(pid == 0){
    char *arr[] = {NULL};
     char *arr1[] = {NULL};
arr[0]= argv[1];
    printf("soy el proceso hijo\n");
    execve(argv[1],arr,arr1);
    //execv(argc,argv);
    return 10;
} else{
    int status;
printf("soy el proeso padre y hijo es %u\n", pid);

wait(&status);
printf("termino despues del hijo y estatus %d\n", status);

}

printf("hola mundo\n");
    return 0;
}