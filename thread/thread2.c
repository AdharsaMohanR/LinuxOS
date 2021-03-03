// C++ code to find maximum of an array using Multithreading 
#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#define max 16  
#define Th_max 4  
int a[max] = { 2,3,5, 10, 11, 13, 14, 18, 19, 22, 23, 27, 40, 55, 180, 210 };  
int max_n[Th_max] = { 0 }; 
int th_no = 0; 
void max1(void* arg) 
{ 
    int k, num = th_no++; 
    int max2 = 0; 
  
    for (k = num * (max / 4); k < (num + 1) * (max / 4); k++) { 
        if (a[k] > max2) 
            max2 = a[k]; 
    } 
  
    max_n[num] = max2; 
} 
int main() 
{ 
    int max2 = 0; 
    int k; 
    pthread_t threads[Th_max]; 
    for (k = 0; k < Th_max; k++) 
        pthread_create(&threads[k], NULL, 
                       maximum, (void*)NULL); 
    for (k= 0; k < Th_max; k++) 
        pthread_join(threads[k], NULL); 
    for (k = 0; k < Th_max; k++) { 
        if (max_n[k] > max2) 
            max2 = max_n[k]; 
    } 
  
    printf("Maximum is : %d", max2); 
  
    return 0; 
} 

    
