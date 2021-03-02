#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
    FILE *f1, *f2; 
    char f[100], k; 
  
    printf("Enter the filename to read\n"); 
    scanf("%s", f); 
  
    // Open one file for reading 
    f1 = fopen(f, "r"); 
    if (f1 == NULL) 
    { 
        printf("Cannot open file %s \n", f); 
        exit(0); 
    } 
  
    printf("Enter the filename to write \n"); 
    scanf("%s", f); 
  
    // Open another file for writing 
    f2 = fopen(f, "w"); 
    if (f2 == NULL) 
    { 
        printf("Cannot open file %s \n", f); 
        exit(0); 
    } 
  
    // Read contents from file 
    k = fgetc(f1); 
    while (k != EOF) 
    { 
        fputc(k, f2); 
        k = fgetc(f1); 
    } 
  
    printf("\nContents copied to %s", f); 
  
    fclose(f1); 
    fclose(f2); 
    return 0; 
}