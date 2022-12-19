/*
* Programming Part HW#2
* Author - Roshan Poudel
* All the functions are written in the same file and the tests are carried out in the main function

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *find_smallest(int *a, int n);
int strbegin(char *s, char *t);

int main()
{

    //------------------ Testing the first function hardcoded way ---------------------------------------------------------------------

    // int *address1;
    // int *address2;
    // int *address3;

    // int t1[] = {58, 34, 48, 61, 53, 24, 98, 80, 12, 18, 45};
    // int t2[] = {23, 31, 23, 10, 67, 0, 07};
    // int t3[] = {100, 20, 3, 40, 56, 6};

    // address1 = find_smallest(t1, 11);
    // printf("The address of the smallest element %d is %p\n", *address1, address1);

    // address2 = find_smallest(t2, 7);
    // printf("The address of the smallest element %d is %p\n", *address2, address2);

    // address3 = find_smallest(t3, 6);
    // printf("The address of the smallest element %d is %p\n\n", *address3, address3);

    //---------------------Testing the first function proper way letting user choose create their array -------------------------------

    int *arr, *address, length;
    printf("\nTesting findsmallest function\n\n");
    printf("Enter the length of the array you want to make\n");
    scanf("%d", &length);
    arr = (int *)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++)
    {
        printf("Enter %d th array: ", i + 1);
        scanf("%d", &arr[i]);
    }

    address = find_smallest(arr, length);
    printf("\nThe address of the smallest element %d is %p\n\n", *address, address);

    free(arr);
    arr = NULL;

    //----------------- testing second function hardcoded way --------------------------------------------------------------------------

    // char cstr1[] = "programming";
    // char cstr2[] = "prog";
    // char cstr3[] = "all";

    // if (strbegin(cstr1, cstr2) == 1)
    // {
    //     printf("The string \"%s\" occurs at the beginning of \"%s\".\n", cstr2, cstr1);
    // }
    // else
    // {
    //     printf("The string \"%s\" does not occur at the beginning of \"%s\".\n", cstr2, cstr1);
    // }

    // if (strbegin(cstr1, cstr3) == 1)
    // {
    //     printf("The string \"%s\" occurs at the beginning of \"%s\".\n", cstr3, cstr1);
    // }
    // else
    // {
    //     printf("The string \"%s\" does not occur at the beginning of \"%s\".\n", cstr3, cstr1);
    // }

    // if (strbegin(cstr2, cstr3) == 1)
    // {
    //     printf("The string \"%s\" occurs at the beginning of \"%s\".\n", cstr3, cstr2);
    // }
    // else
    // {
    //     printf("The string \"%s\" does not occur at the beginning of \"%s\".\n", cstr3, cstr2);
    // }

    // --------------- Advanced testing of second function asking user for the input using the dynamic array allocation --------------------

    printf("Testing strbegin function\n\n");
    char *cstr1, *cstr2;
    cstr1 = (char *)malloc(sizeof(char) * 254);
    cstr2 = (char *)malloc(sizeof(char) * 254);

    printf("Enter the str1\n");
    scanf("%s", cstr1);

    printf("Enter the str2\n");
    scanf("%s", cstr2);

    if (cstr1 == NULL || cstr2 == NULL)
    {
        printf("Error! Malloc Failed. Program terminated.\n");
        exit(1);
    }

    if (strbegin(cstr1, cstr2) == 1)
    {
        printf("The string %s occurs at the beginning of %s.\n", cstr2, cstr1);
    }
    else if (strbegin(cstr1, cstr2) == 0)
    {
        printf("The string %s does not occur at the beginning of %s.\n", cstr2, cstr1);
    }




    free(cstr1);
    free(cstr2);
    cstr1 = NULL;
    cstr2 = NULL;

    return 0;
}

int *find_smallest(int *a, int n)
{

    int *smallest = a;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < *smallest)
        {
            smallest = &a[i];
        }
    }
    return smallest;
}

int strbegin(char *s, char *t)
{
    int returnval;

    // while (*s != '\0' && *t != '\0')
    // {
    //     if (*t == *s)
    //     {
    //         returnval = 1;
    //     }

    //     else
    //     {
    //         returnval = 0;
    //         break;
    //     }

    //     s++;
    //     t++;
    // }

    for (; *s && *t; s++, t++)
    {
        if (*t == *s)
        {
            returnval = 1;
        }
        else
        {
            returnval = 0;
        }
    }
    return returnval;
}