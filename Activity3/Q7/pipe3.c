#include"pipe.h"
void main()
{
    char s[256]="start";
    int fifo_write,fifo_read;
    while(strcmp(s,"end")!=0)
    {
        fifo_write= open("pipe1a",O_WRONLY);
        if(fifo_write<0)
            printf("\nFiled to  open pipe");
        else
        {
            printf("start: ");
            scanf("%s",s);
            write(fifo_write,s,255*sizeof(char));
            close(fifo_write);
        }
        fifo_read=open("pipe2a",O_RDONLY);
        if(fifo_read<0)
            printf("\nFailed to write pipe");
        else
        {
            read(fifo_read,s,255*sizeof(char));
            close(fifo_read);
            printf("\n%s",s);
        }
    }
}