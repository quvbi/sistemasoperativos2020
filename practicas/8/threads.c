
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
unsigned saldo;
sem_t semSaldo;
void *addTSaldo(void *arg){
    sem_wait(&semSaldo);
    unsigned  valorInicial = saldo;
    unsigned  saldoFinal = valorInicial + 500;
    saldo = saldoFinal;
         printf("El saldo actual es %d y esl final es %d \n", valorInicial, saldoFinal);
    sem_post(&semSaldo);

    pthread_exit(NULL);
}

int main(){
    unsigned NUM_THREADS = 100;
    saldo = 0;
    sem_init(&semSaldo, 0,1);
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, addTSaldo, NULL);
    }

    for (int i = 0; i <NUM_THREADS; i++) {

    pthread_join(threads[i], NULL);
    }

        printf("El saldo final es %d \n", saldo);
        pthread_exit(NULL);
}