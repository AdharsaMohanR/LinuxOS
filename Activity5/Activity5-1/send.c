#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int ret;
	mqd_t mqid;
	struct mq_attr at;
	at.mq_msgsize=200;
	at.mq_maxmsg=15;
	mqid=mq_open("/mque",O_WRONLY|O_CREAT,0666,&at);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}
	char s[]="Hello Message queue";
	int l=strlen(s);
	ret=mq_send(mqid,s,l+1,5);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}
	struct mq_attr at1;
	at1.mq_msgsize=256;
	at1.mq_maxmsg=20;
	mqd_t mqid2;
	mqid2=mq_open("/mque2",O_RDONLY|O_CREAT,0666,&at1);
	if(mqid2<0)
	{
		perror("mq_open");
		exit(1);
	}
	char buffer[8192];
	int m_length=256,pri;
	int n_bytes=mq_receive(mqid2,buffer,m_length,&pri);
	if(n_bytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buffer[n_bytes]='\0';
	printf("receive msg from receiver :%s,nbytes=%d,prio=%d\n",buffer,n_bytes,pri);
	mq_close(mqid);
	mq_close(mqid2);
	return 0;
}

