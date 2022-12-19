#include <stdio.h>
#include <math.h>
#include <string.h>

float convertBits(char[], char[]);

int main()
{
    float ans;

    ans = convertBits("1", "110");
    printf("%f", ans);
    return 0;
}

float convertBits(char left[], char right[])
{
    char binleft[33], binwithoutdot[33], binright[33], stringsafterdecimal[33];
    int x_val = 0, k = 0, wheredot = 0;

    // copying left strings to binleft and binwithoutdot
    strcpy(binleft, left);
    strcpy(binwithoutdot, left);
    // copying right strings to binright
    strcpy(binright, right);
    // concatenating right to left without decimal point Eg if binleft == "100101"
    // and binright == "101"
    strcat(binwithoutdot, binright);
    // adding dot to the end of the left strings
    strcat(binleft, ".");
    // adding right strings to the end of the "left strings with the decimal point"
    strcat(binleft, binright);

    // Now, we need to convert the resultant binary string to fraction in the form
    //  (x/2^k) to get the decimal value

    // getting the x value
    int power_of_2 = 0;
    for (int i = strlen(binwithoutdot) - 1; i >= 0; i--)
    {
        if (binwithoutdot[i] == '1')
        {
            x_val += pow(2, power_of_2);
        }
        power_of_2++;
    }

    //Getting k
    for (int i = 0; binleft[i] != '.'; i++)
    {
        wheredot++;
    }
    strcpy(stringsafterdecimal, &binleft[wheredot + 1]);

    for (int i = 0; i < strlen(stringsafterdecimal); i++)
    {
        k++;
    }

    return (float)(x_val / pow(2, k));
}