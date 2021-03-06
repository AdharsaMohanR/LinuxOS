#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

/*
This program provides a possible solution for producer-consumer problem using mutex and semaphore.
*/

#define MaxItems 5 // Maximum items a producer can produce or a consumer can consume
#define BufferSize 5 // Size of the buffer

int in = 0;
int out = 0;
int it=0;
int buf[BufferSize];
pthread_mutex_t mutex;

void *producer(void *p)
{   
    if(in==BufferSize-1)
    {
        printf(" Stack is full \n");
    }
    else
    {
     for(int k = 0; k < MaxItems; k++) {
        it = rand(); // Produce a random item
        pthread_mutex_lock(&mutex);
        /* put value item into the buffer */
        buf[in] = it;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)p),buf[in],in);
        in = (in + 1) % BufferSize;     
        pthread_mutex_unlock(&mutex);
     }
    }
}
void *consumer(void *c)
{   
    if(out==BufferSize-1)
    {
        printf(" Stack is full\n");
    }
    else
    {
     int it=0;
     for(int k = 0; k < MaxItems; k++) {
        pthread_mutex_lock(&mutex);
        /* take one unit of data from the buffer */
        it = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)c),it, out); 
        out = (out + 1) % BufferSize;     
        pthread_mutex_unlock(&mutex);
     }
    }
}

int main()
{   

    pthread_t p[4],c[4];
    pthread_mutex_init(&mutex, NULL);

    int arr[5] = {1,2,3,4}; //Just used for numbering the producer and consumer

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

    pthread_mutex_destroy(&mutex);

    return 0;
}

    
