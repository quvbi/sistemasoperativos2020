#include <pthread.h>
#include <stdio.h>

//int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start))

typedef struct hd {
	int hid;
	char *msg;
} ThreadData;

void *hello(void *arg){
	
	ThreadData *td = (ThreadData *)arg;
	printf("%s %d\n", td->msg, td->hid);
	free(arg);
	pthread_exit(NULL);
}

int main(){
	
	pthread_t newThread;
	//ThreadData td[10];
	//td.msg = "Hello desde el hilo\n";
	for(int i = 0; i<10;i++){
		ThreadData *td = (ThreadData *)calloc(1,sizeof(ThreadData));
		td->hid = i;
		td->msg = "Hello desde el hilo\n";

	pthread_create(&newThread, NULL, hello, (void *)td);
	}
	pthread_exit(NULL);
	return 0;
}