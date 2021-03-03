#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
	int ret,s;
	printf("Pid=%d\n",getpid());
	ret=fork();
	if(ret<0)
	{
		perror("fork");
		exit(1);
	}
	if(ret==0)
	{
		printf("Pid=%d,Ppid=%d\n",
			getpid(),getppid());
		int p;
        p=execl("/usr/bin/gcc","gcc","processes1.c",NULL);
		if(p<0)
		{
			perror("execl");
			exit(1);
		}
		exit(5);
	}
	else	
	{
		printf("Pid=%d,Ppid=%d\n",
			getpid(),getppid());
		waitpid(-1,&s,0); 
		printf("status=%d\n",
			WEXITSTATUS(s));
	}
	return 0;
}