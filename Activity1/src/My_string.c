#include "My_string.h"
size_t mystrlen(const char *s1){
    return strlen(s1);
}
char* mystrcpy(char* s2, const char* s3){
    return strcpy(s2,s3);
}
char* mystrcat(char *s2, const char *s3){
    return strcat(s2,s3);
}
int mystrcmp(const char *s2, const char *s3 ){
    return strcmp(s2,s3);
}
