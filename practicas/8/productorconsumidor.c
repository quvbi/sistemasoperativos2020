
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUF_SIZE 10

sem_t mutexBuffer;
 int buffer[BUF_SIZE];
sem_t semEspacios;  //indicar espacios disponibles
sem_t semDatos; // indicar que hay algo que consumir

void * productor(void *arg){
    int i = 0;
        while(1){
        
        sleep(1);

        sem_wait(&semEspacios);
        sem_wait(&mutexBuffer);

        buffer[i] = rand();

        sem_post(&mutexBuffer);
        sem_post(&semDatos);
        i ++;
            if (i == BUF_SIZE ) {
                i =0;
            }
        }
        pthread_exit(NULL);
}


void * consumer(void *arg){
    int i = 0;
    while (1) {
        sem_wait(&semDatos);
        sem_wait(&mutexBuffer);
        int dato = buffer[i];
        buffer[i]  = 0;

        sem_post(&mutexBuffer);
        sem_post(&semEspacios);
        printf("El valor leido es %d \n", dato);
        sleep(2);
        i++;
        if (i == BUF_SIZE) {
        i = 0;
        }
    }

    pthread_exit(NULL);
}

int main(){
    sem_init(&mutexBuffer, 0, 1);
    sem_init(&semEspacios, 0, BUF_SIZE);
    sem_init(&semDatos, 0, 0);
    pthread_t tproducer;
    pthread_t tconsumer;
    pthread_create(&tproducer, NULL, productor, NULL);
        pthread_create(&tconsumer, NULL, consumer, NULL);
        pthread_exit(NULL);
}