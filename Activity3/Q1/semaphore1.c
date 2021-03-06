#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#define MaxItems 5 
#define BufferSize 5
sem_t e;
sem_t f;
int out = 0;
int in = 0;
int it=0;
int buffer[BufferSize];
void *producer(void *no)
{   
    if(in==BufferSize-1)
    {
        printf(" Stack is full \n");
    }
    else
    {
     for(int k = 0; k < MaxItems; k++) {
        item = rand(); 
        sem_wait(&e);
        buffer[in] = it;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)no),buffer[in],in);
        in = (in + 1) % BufferSize;     
        sem_post(&f);
     }
    }
}
void *consumer(void *c)
{   
    if(out==BufferSize-1)
    {
        printf("Stack is full\n");
    }
    else
    {
     int it=0;
     for(int k = 0; k < MaxItems; k++) {
        sem_wait(&full);
        /* take one unit of data from the buffer */
        it = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)c),it, out); 
        out = (out + 1) % BufferSize;     
        sem_post(&empty);
     }
    }
}

int main()
{   

    pthread_t p[5],c[5];
    sem_init(&e,0,BufferSize);
    sem_init(&f,0,0);

    int arr[5] = {1,2,3,4,5}; 

    for(int k = 0; k < 5; k++) {
        pthread_create(&p[k], NULL, (void *)producer, (void *)&arr[k]);
    }
    for(int k = 0; k < 5; k++) {
        pthread_create(&c[k], NULL, (void *)consumer, (void *)&arr[k]);
    }

    for(int k = 0; k < 5; k++) {
        pthread_join(p[k], NULL);
    }
    for(int k = 0; k < 5; k++) {
        pthread_join(c[k], NULL);
    }

    sem_destroy(&e);
    sem_destroy(&f);

    return 0;
}

    
