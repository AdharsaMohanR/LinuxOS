#include <iostream> 
#include <pthread.h> 
#define MAX 16  
#define MAX_THREAD 4 
using namespace std; 
int a[] = {2,3,5, 10, 11, 13, 14, 18, 19, 22, 23, 27, 40, 55, 180, 210 }; 
int sum[4] = { 0 }; 
int p = 0; 
void* sum_arr(void* arg) 
{  
    int thread_p = p++; 
  
    for (int i = thread_p * (MAX / 4); i < (thread_p + 1) * (MAX / 4); i++) 
        sum[thread_p] += a[i]; 
}
int main() 
{ 
    pthread_t th[MAX_THREAD];  
    for (int k = 0; k< MAX_THREAD; k++) 
        pthread_create(&threads[k], NULL, sum_arr, (void*)NULL); 
    for (int k = 0; k < MAX_THREAD; k++) 
        pthread_join(th[k], NULL); 
    int total = 0; 
    for (int k = 0; k< MAX_THREAD; k++) 
        total += sum[i]; 
    cout << "Sum :" << total << endl; 
    return 0; 
} 

   
  
