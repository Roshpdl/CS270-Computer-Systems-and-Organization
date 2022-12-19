/*
Author: Roshan Poudel
Program to convert given bit strings to its equivalent decimal value
Programming Part of Howework 5; CS270
Another (more efficient way) of doing the same function using bitshifting is given in the file convertBitsFinal.c
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

float convertBits(char[], char[]);

int main()
{
    char binleft[33], binright[33], userinp = 'Y';
    float ans;
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

float convertBits(char left[], char right[])
{
    char binwithdot[33], binwithoutdot[33], stringsafterdecimal[33];
    int x = 0, k = 0, wheredot = 0;

    // copying left strings to binleft and binwithoutdot.
    // We are deep copying only left string and not the right string because
    // left strings needs to be modified for our use and we do not want to reflect those changes in the argument
    // However, we only need to access (and not modify!) right string. So, no need to deep copy right strings.
    strcpy(binwithoutdot, left);
    strcpy(binwithdot, left);

    // concatenating right to left strings. Eg: if left = "100101"
    // and right = "101", then bin without decimal point will be "100101101"
    strcat(binwithoutdot, right);

    // adding dot to the end of the left strings
    strcat(binwithdot, ".");
    // adding right strings to the end of the "left strings (which contains the decimal point at last)"
    strcat(binwithdot, right);

    // Now, we need to convert the resultant binary string to fraction in the form
    //  (x/2^k) to get the decimal value

    // getting the x value
    int power_of_2 = 0;
    for (int i = strlen(binwithoutdot) - 1; i >= 0; i--)
    {
        if (binwithoutdot[i] == '1')
        {
            x += pow(2, power_of_2);
        }
        power_of_2++;
    }

    // Getting k
    for (int i = 0; binwithdot[i] != '.'; i++)
    {
        wheredot++;
    }
    // copying the values after the decimal point to the variable stringsafterdecimal
    strcpy(stringsafterdecimal, &binwithdot[wheredot + 1]);

    for (int i = 0; i < strlen(stringsafterdecimal); i++)
    {
        k++;
    }
    // returning the required decimal value using x/2^k
    return (float)(x / pow(2, k));
}