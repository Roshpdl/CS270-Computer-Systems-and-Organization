/*
Author: Roshan Poudel
Program to convert given bit strings to its equivalent decimal value
Homework 5; Programming Part CS270
Another (less efficient way) of doing the same function using C-strings is given in the file convertbits1stapproach.c
*/


#include <stdio.h>
#include <string.h>

double convertBits(char [], char []);

int main()
{
    char binleft[33], binright[33], userinp = 'Y';
    double ans;
    //continue until the user input is not N
    while (userinp == 'Y')
    {
        puts("\nEnter the left string");
        scanf("%s", binleft);
        puts("Enter the right string");
        scanf("%s", binright);
        ans = convertBits(binleft, binright);
        printf("\n%s.%s = %f\n", binleft, binright, ans);
        puts("\nContinue? Y/N");
        scanf("%s", &userinp);
    }
    return 0;
}

double convertBits(char left[], char right[])
{
    //initializing the left number
    int l_num = 0;

    //looping through the left strings
    for (int i = 0; i <= strlen(left); i++)
    {
        if (left[i] == '1')
        {
            //x << n means multiplying x by 2^n
            l_num += (1 << (strlen(left) - i - 1));
        }
    }

    //initializing the decimal for right side of the binary string
    double r_num = 0.0;

    //looping through right strings
    for (int i = 0; i <= strlen(right); i++)
    {
        if (right[i] == '1')
        {
            // dividing 1 by the increasing negative power of 2 and adding to r_num to get the decimal equivalent of the string
            r_num += (1.0/ (double)(1 << (i + 1)));
        }
    }
    //Finally, adding the converted left and right strings
    double converted = l_num + r_num;
    return converted;
}

