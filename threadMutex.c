#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int mails = 0;
pthread_mutex_t mutex;

void* routine(){
    
    for(int i = 0; i<1000000; i++){
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
}

void main(){
    pthread_t pth1, pth2;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&pth1, NULL, &routine, NULL);
    pthread_create(&pth2, NULL, &routine, NULL);
    pthread_join(pth1, NULL);
    pthread_join(pth2, NULL);
    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %d \n", mails);
}