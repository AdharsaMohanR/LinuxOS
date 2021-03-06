#include"pipe.h"
void main() 
{
    int b;
    b= mkfifo("pipe1a",0666);
    if(b<0)
        printf("\npipe1a not created");
    else
        printf("\npipe1a created");
    int c;
    c = mkfifo("pipe2a",0666);
    if(c<0)
        printf("\npipe2a not created");
    else
        printf("\npipe2a is created\n");
}