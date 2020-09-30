#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void signalHandler(int signum){
    int status;
    wait(&status);
        printf("mi hijo termina con estatus %d\n", status);

}

int main(int argc, char **argv){
signal(17,signalHandler);
unsigned pid = fork();
if(pid == 0){
sleep(5);

    printf("soy el proceso hijo\n");
   // execve(argv[1],arr,arr1);
    //execv(argc,argv);
    return 10;
} else{
   
printf("soy el proeso padre y hijo es %u\n", pid);
while(1){
        sleep(2);
        printf("trabjando \n");

    }

}

printf("hola mundo\n");
    return 0;
}