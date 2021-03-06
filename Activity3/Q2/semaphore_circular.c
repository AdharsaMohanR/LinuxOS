#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#define MaxItems 5 // Maximum items a producer can produce or a consumer can consume
#define BufferSize 5 // Size of the buffer

sem_t e;
sem_t f;
int in = 0;
int out = 0;
int buf[BufferSize];

void *producer(void *p)
{   
    int it;
    for(int k= 0; k < MaxItems; k++) {
        it = rand(); // Produce a random item
        sem_wait(&e);
        /* wait for space in buffer */
        while (((in + 1) % BufferSize) == out)
        {
        /* put value item into the buffer */
           buf[in] = it;
           printf("Producer %d: Insert Item %d at %d\n", *((int *)p),buf[in],in);
           in = (in + 1) % BufferSize;     
        }
        sem_post(&f);
    }
}
void *consumer(void *c)
{   
    int it=0;
    for(int k = 0; k < MaxItems; k++) {
        sem_wait(&f);
        /* wait for buffer to fill */
        while (in == out) 
        {
        /* take one unit of data from the buffer */
           it = buf[out];
           printf("Consumer %d: Remove Item %d from %d\n",*((int *)c),it, out); 
           out = (out + 1) % BufferSize;     
        }
        sem_post(&e);
    }
}

int main()
{   

    pthread_t p[5],c[5];
    sem_init(&e,0,BufferSize);
    sem_init(&f,0,0);

    int arr[4] = {1,2,3,4}; //Just used for numbering the producer and consumer

    for(int k = 0; k < 4; k++) {
        pthread_create(&p[k], NULL, (void *)producer, (void *)&arr[k]);
    }
    for(int k = 0; k < 4; k++) {
        pthread_create(&c[k], NULL, (void *)consumer, (void *)&arr[k]);
    }

    for(int k = 0; k < 4; k++) {
        pthread_join(p[k], NULL);
    }
    for(int k = 0; k < 5; k++) {
        pthread_join(c[k], NULL);
    }

    sem_destroy(&e);
    sem_destroy(&f);

    return 0;
}

