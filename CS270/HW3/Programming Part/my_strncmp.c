/*
 * my_strncmp.c
 * Author: Roshan Poudel
 * Programming Part 1 and 2
 * HW #3
 * Question: Create your own version of my_strncmp and test it following the given guidelines.
 */



#include <stdio.h>
#include <stdlib.h>

int mystrncmp(const char *str1, const char *str2, int n);

int main()
{

    char *s1 = (char *)malloc(sizeof(char) * 256);
    char *s2 = (char *)malloc(sizeof(char) * 256);
    int num, result;
    printf("To exit the program, hit space and return key at the end of your second string\n");

    while (1)
    {
        printf("Enter two strings to compare:\n" );

        scanf("%s %s", s1, s2);
        if (getchar() == ' ') // if the user hits space at last and hits return key, the program should terminate, otherwise continues
        {
            exit(1);
        }
        printf("How many letters do you want to compare?\n");
        scanf("%d", &num);

        result = mystrncmp(s1, s2, num);

        if (result < 0)
        {
            printf("%s is less than %s\n", s1, s2);
        }

        else if (result > 0)
        {
            printf("%s is less than %s\n", s2, s1);
        }

        else
        {
            printf("%s is same as %s\n", s1, s2);
        }

        s1 = realloc(s1, sizeof(char) * 256); //I just searched if there's any way to reallocate the same space. And discovered realloc function.
        s2 = realloc(s2, sizeof(char) * 256);
    }

    return 0;
}

// *(var + i) --> discovered it the hard way. Was using both index and the pointer to traverse through the string.

int mystrncmp(const char *str1, const char *str2, int n)
{
    for (; *str1 != '\0' && *str2 != '\0' && *str1 == *str2; n--, str1++, str2++); //traverse the string as long as the letters are equal
    return *str1 - *str2; 
}
