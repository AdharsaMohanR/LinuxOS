#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int ret,m_bytes;
	struct mq_attr at;
	at.mq_msgsize=256;
	at.mq_maxmsg=20;
	mqd_t mqid;
	mqid=mq_open("/mque",O_RDONLY|O_CREAT,0666,&at);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}
	char buffer[8192];
	int maxlen=256,pri;
	m_bytes=mq_receive(mqid,buffer,maxlen,&pri);
	if(m_bytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buffer[m_bytes]='\0';
	printf("receive msg from sender:%s,nbytes=%d,prio=%d\n",buffer,m_bytes,pri);
	mqd_t mqid2;
	struct mq_attr at1;
	at1.mq_msgsize=256;
	at1.mq_maxmsg=20;
	mqid2=mq_open("/mque2",O_WRONLY|O_CREAT,0666,&at1);
	for(int count=0;buffer[count]!=NULL;count++)
    {
        if(buffer[count]>='A' && buffer[count]<='Z')
            buffer[count]=buffer[count]+32;
        else if(buffer[count]>='a' && buffer[count]<='z')
            buffer[count]=buffer[count]-32;
    }
	ret=mq_send(mqid2,buffer,m_bytes+1,2);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}
	mq_close(mqid);
	mq_close(mqid2);
	return 0;
}