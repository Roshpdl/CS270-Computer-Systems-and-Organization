/*
 * Version 1 (bruteforce) Homework 4 Q no 2.
 * Program to convert a given hexadecimal number into its decimal equivalent
 * Author: Roshan Poudel
 * October 28, 2022
 * Using regular indexing to traverse through the hexadecimal string
 * A similar polished version is available.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int hextodecconverter(char *);
int hexalphabet(char);
int isvalidhexpresent(char);

int main()
{
    char *num = (char *)malloc(33);
    int result;
    puts("\nEnter a valid hexadecimal number:");
    scanf("%s", num);

    for (int i = 0; i < strlen(num); i++)
    {
        if (isvalidhexpresent(num[i]))
        {
            result = 1;
        }
        else
        {
            result = 0;
            break;
        }
    }

    if (result == 0)
    {
        printf("Please Enter a valid hexadecimal number\n");
    }
    else
    {
        result = hextodecconverter(num);
        printf("The decimal value of %s is %d\n", num, result);
    }

    free(num);
    num = NULL;

    return 0;
}

int hextodecconverter(char hexnum[])
{

// index to traverse through the string, power to raise over 16, decval is the returned integer value after conversion
    int index = (strlen(hexnum)) - 1, power = 0, decval = 0;

    while (index >= 0)
    {
        // For numeric hexadecimal values
        if ((int)(hexnum[index] - '0') <= 9) // typecasting type str to int...Here, we are subtracting '0' (ASCII value of 0 is 48) because if we straight typecast it then '5' would be sth like 53. So, first subtracting them subtracts their ascii values like '5'(ASCII = 53)- '0'(ASCII = 48)
        {
            decval += (int)(hexnum[index] - '0') * pow(16, power); 
        }
        // For alphabetic hexadecimal values
        else
        {
            decval += hexalphabet(hexnum[index]) * pow(16, power);
        }
        index--;
        power++;
    }
    return decval;
}

int hexalphabet(char c) // takes hexadecimal alphabet and returns its integer equivalent.
{
    switch (c)
    {
    case 'A':
        return 10;
    case 'B':
        return 11;
    case 'C':
        return 12;
    case 'D':
        return 13;
    case 'E':
        return 14;
    case 'F':
        return 15;
    default:
        return 0;
    }
}

int isvalidhexpresent(char c)
{
    char hexalpha[16] = {'A', 'B', 'C', 'D', 'E', 'F', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int present = 0;
    for (int i = 0; i < 16; i++)
    {
        if (hexalpha[i] == c)
        {
            present = 1;
            break;
        }
    }
    return present;
}