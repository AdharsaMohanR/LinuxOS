#include "count.h"

int l_count, c_count, w_count;
void count()
{
	int f1,n_bytes;
	char ch[100];

  f1=open("file1.txt",O_RDONLY);
	  if(f1<0)
	  {
		  perror("open");
		  exit(1);
	  }

  w_count = 0;
  l_count= 0;
    while(n_bytes=read(f1,ch,sizeof(ch)))
    {
        for(int k=0;k<n_bytes;k++)
        {
            // Check new line
            if (ch[i] == '\n')
               l_count++;
            /* Check word_count */
            if (ch[k] == ' ' || ch[k] == '\t' || ch[k] == '\n')
               w_count++;
        }
        c_count=n_bytes;
    }
    /* Close files to release resources */
    close(f1);
}

int lineCount()
{
  return l_count;
}
int charCount()
{
  return c_count;
}
int wordCount()
{
  return w_count;
}
