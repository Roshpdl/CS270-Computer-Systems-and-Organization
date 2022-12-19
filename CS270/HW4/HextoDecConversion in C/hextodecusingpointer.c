/*
 * Program to convert a given hexadecimal number into its decimal equivalent
 * Author: Roshan Poudel
 * October 28, 2022
 * Almost same as hextodec1.c but I used pointer to traverse through the hexadecimal string. Tried my luck, it worked!
 * Did not implement the error checking for valid hexdec coz its already done in hextodec1.c
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int hextodecconverter(char *);
int hexalphabet(char);

int main()
{
    char *num = (char *)malloc(33);
    int result;
    puts("Enter a valid hexadecimal number\n");
    scanf("%s", num);
    result = hextodecconverter(num);
    printf("The decimal value of %s is %d", num, result);

    free(num);
    num = NULL;

    return 0;
}

int hextodecconverter(char *hexnum)
{
    char *ptr = hexnum;
    ptr = ptr + (strlen(hexnum) - 1);
    int index = (strlen(hexnum)) - 1, power = 0, decval = 0;

    while (index >= 0)
    {
        // For numeric hexadecimal values
        if ((int)(*ptr - '0') <= 9) // typecasting type str to int...Here, we are subtracting '0' (ASCII value of 0 is 48) because if we straight typecast it then '5' would be sth like 53. So, first subtracting them subtracts their ascii values like '5'(ASCII = 53)- '0'(ASCII = 48)
        {
            decval += (int)(*ptr - '0') * pow(16, power);
        }
        // For alphabetic hexadecimal values
        else
        {
            decval += hexalphabet(*ptr) * pow(16, power);
        }
        ptr--;
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
