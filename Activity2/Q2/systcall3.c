#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
// function declaration 
void sighup(); 
void sigint(); 
void sigquit(); 
void main() 
{ 
    int pid; 
    if ((pid = fork()) < 0) { 
        perror("fork"); 
        exit(1); 
    } 
  
    if (pid == 0) { 
        signal(SIGHUP, sighup); 
        signal(SIGINT, sigint); 
        signal(SIGQUIT, sigquit); 
        for (;;) 
            ; 
    } 
  else 
    { 
        printf("\nPARENT: sending SIGHUP\n\n"); 
        kill(pid, SIGHUP); 
  
        sleep(3); 
        printf("\nPARENT: sending SIGINT\n\n"); 
        kill(pid, SIGINT); 
  
        sleep(3);
        printf("\nPARENT: sending SIGQUIT\n\n"); 
        kill(pid, SIGQUIT); 
        sleep(3); 
    } 
} 
void sighup() 
 { 
    signal(SIGHUP, sighup);
    printf("CHILD:  received a SIGHUP\n"); 
} 
void sigint() 
  { 
    signal(SIGINT, sigint); 
    printf("CHILD:  received a SIGINT\n"); 
} 
void sigquit() 
{ 
    printf("Child process is killed!!!\n"); 
    exit(0); 
} 

    
