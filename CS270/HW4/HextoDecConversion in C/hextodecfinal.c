/*
 * Program to convert a given hexadecimal number into its decimal equivalent
 * Author: Roshan Poudel
 * October 28, 2022
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

int hextodecconverter(char[]);
int validhexpresent(char);

int main()
{
    char num[32];
    int result;
    puts("\nEnter a valid hexadecimal number:");
    scanf("%s", num);

    for (int i = 0; i < strlen(num); i++)
    {
        if (validhexpresent(num[i]))
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

    return 0;
}

int hextodecconverter(char hexnum[])
{
    // index to traverse (starting from the end) through the string
    // power to raise over 16
    // decval is the returned integer value after conversion
    // eqdigit to keep track of the equivalent integer value of a single hex number
    int index = (strlen(hexnum)) - 1, power = 0, decval = 0, eqdigit = 0;

    for (; index >= 0; index--)
    {
        switch (hexnum[index])
        {
        case 'A':
            eqdigit = 10;
            break;
        case 'B':
            eqdigit = 11;
            break;
        case 'C':
            eqdigit = 12;
            break;
        case 'D':
            eqdigit = 13;
            break;
        case 'E':
            eqdigit = 14;
            break;
        case 'F':
            eqdigit = 15;
            break;
        default:
            eqdigit = (int)(hexnum[index] - '0');
            // Typecasting type str to int
            // Here, we are subtracting '0' (ASCII value of 0 is 48) because if we straight typecast it
            // then lets say if hexnum[index] = '5', then it would be sth like 53.
            // So, first subtracting them subtracts their ascii values like '5'(ASCII = 53)- '0'(ASCII = 48) = '5' and then typecast to int.
        }

        decval += (eqdigit)*pow(16, power);
        power++;
    }
    return decval;
}

int validhexpresent(char c)
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