/* Function to duplicate a given string*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *duplicate(const char *p); //prototype of func

int main()
{
    char *str1 = malloc(sizeof(char) * 254);
    char *str2 = malloc(sizeof(char) * 254);
    str1 = "String"; //to be copied
    str2 =strdup(str1);
    printf("String is : %s\n", str2);
    return(0);
}

char *duplicate(const char *p)
{
    char *q = malloc(sizeof(char) * 254);
    strcpy(q,p);
    return q;
}