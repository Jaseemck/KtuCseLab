#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

sem_t chopstick[5],eat[5];
int chop[5]={0,1,2,3,4};


void *phil(void *arg){
    int a=*(int*)arg;
    printf("\nPhilosopher %d is hungry\n",a);
    sem_wait(&chopstick[a]);
    printf("\nPhilosopher %d picked up chopstick %d\n",a,a);
    sem_wait(&chopstick[(a+1)%5]);
    printf("\nPhilosopher %d picked up chopstick %d\n",a,(a+1)%5);
    printf("\nPhilosopher %d is eating\n",a);
    sleep(rand()%5);
    printf("\nPhilosopher %d dropped chopstick %d\n",a,(a+1)%5);
    printf("\nPhilosopher %d dropped chopstick %d\n",a,a);
    printf("\nPhilosopher %d is thinking\n",a);
    sem_post(&chopstick[(a+1)%5]);
    sem_post(&chopstick[a]);
}

void main(){
    int i;
    pthread_t t[5];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
    
    for(i=0;i<5;i++){
        sem_init(&chopstick[i],0,1);
        sem_init(&eat[i],0,1);
    }
    for(i=0;i<5;i++){
        pthread_create(&t[i],&attr,phil,&chop[i]);
        sleep(rand()%3);
    }
    sleep(10);
    for(i=0;i<5;i++){
        pthread_join(t[i],NULL);
    }
}
