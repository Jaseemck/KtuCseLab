#include<stdio.h>
#include<semaphore.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

#define MAX_BUFFER 5

sem_t sem_pc,empty,full;
int con_count=0,pro_count=0;
int buff[MAX_BUFFER];

void *producer(void *p){
    int i;
    for(i=0;i<10;i++){
        sem_wait(&empty);
        sem_wait(&sem_pc);
        printf("\nProducer is producing\n");
        buff[pro_count]=i+1;
        printf("  Produced item is %d\n",buff[pro_count]);
        pro_count++;
        if(pro_count==MAX_BUFFER)
            pro_count=0;
        sem_post(&sem_pc);
        sem_post(&full);
        sleep(rand()%2);
    }
}

void *consumer(void *con){
    int i;
    for(i=0;i<10;i++){
        sem_wait(&full);
        sem_wait(&sem_pc);
        printf("\nConsumer is consuming\n");
        printf("  Consumed item is %d\n",buff[con_count]);
        con_count++;
        if(con_count==MAX_BUFFER)
            con_count=0;
        sem_post(&sem_pc);
        sem_post(&empty);
        sleep(rand()%4);
    }
}

void main(){
   
    pthread_t con, pro;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
    
    sem_init(&sem_pc,0,1);
    sem_init(&full,0,0);
    sem_init(&empty,0,MAX_BUFFER);
    
    pthread_create(&pro,&attr,producer,NULL);
    pthread_create(&con,&attr,consumer,NULL);
    
    sleep(20);
    
    pthread_join(pro,NULL);
    pthread_join(con,NULL);
}      
