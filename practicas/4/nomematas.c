
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void signalHandler(int signum){
    printf("hahaha no me matas \n");
}

int main(){
    signal(2, signalHandler);

    while(1){
        sleep(2);
        printf("trabjando \n");

    }
    return 0;
}