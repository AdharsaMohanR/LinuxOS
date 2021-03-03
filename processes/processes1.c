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
        int p;
        char str[20];
        scanf("%s",str);
        p=execl("/usr/bin/pwd",str,NULL);
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
		printf("exit status=%d\n",
			WEXITSTATUS(s));
	}
	return 0;
}
