#include "system_copy.h"

bool copy()
{
	int f,f1,no, flag;

	//file1 in readonly
	f=open("file1.txt",O_RDONLY); 
	f1=open("file2.txt",O_WRONLY|O_CREAT, 0666);
	
	if(f<0 || f1<0)
	{
		perror("open file!");
		exit(1);
	}

	int m_len=128;
	char buffer[m_len];

	//read error
	no=read(f,buffer,m_len);
	if(no<0)
	{
		perror("read file!");
		exit(2);
	}

	flag = write(f1,buffer,no);

	//close
	close(f);
	close(f1);
    if(flag)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
		
