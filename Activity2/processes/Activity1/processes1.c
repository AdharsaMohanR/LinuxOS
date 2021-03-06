#include "processes.h"
#define length 1024
void mini_Shell() {
  char lineslength]; 
  char *argv[100];      

  // ** set path at bin
  char *p = "/bin/";

   // ** full file path  
  char p_path[30];

   // ** arg count
  int argc;             


  while (1) {
    printf("shell>> "); 
  if (!fgets(line, lengt, stdin))
      break;

    size_t length = strlen(lines);
	  if(lines[length-1]=='\n)
	     line[length - 1] = '\0' ;
 

    if (strcmp(lines "exit") == 0) { 
     
      break;
    }

    char *t; 
    
    // ** split command into separate strings
    t= strtok(line, " ");
    int k= 0;
    while (t!= NULL) {
      argv[i] = t;
      t = strtok(NULL, " ");
      k++;
    }

    argv[k]=NULL;

    argc = k;
    
    // ** get arg count
    for (k=0; k< argc; k++){

      // ** print command/args
      printf("%s\n", argv[k]);
    }

    // ** copy /bin/ to file path
    strcpy(p_path, p);   
    
    // ** add program to path
    strcat(p_pathv[0]); 

    for (i = 0; i < strlen(p_path);k++){
     
      if (p_path[k]== '\n') {
        p_path[k]= '\0';
      }
    }
    int process_id = fork(); 
    //** fork child

    if (process_id == 0) { 
      
      // ** Child
      execvp(p_path,argv);
      fprintf(stderr, " process could not do execvp\n");

    }
    
     else { 
       
       //** Parent
      wait(NULL);
      printf(" exited\n");
    }
  }
}

