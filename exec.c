#include "exec.h"
void Compile()
{
    process_id_t process_id=fork();
    int x;
    if (process_id==0)
    { 
    	x=execlp("gcc","gcc","s1.c","-o", "s1.out",NULL);
      exit(127); 
    }
    else
    { 
    	waitprocess_id(process_id,0,0);
    	printf("Parent Process\n");
    }
}