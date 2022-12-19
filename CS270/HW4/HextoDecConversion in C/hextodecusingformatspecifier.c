/*
This is by far the most easiest way to convert hex to decimal
After spending 3 hours creating my version, I got to learn that this way exists too.
My version is also working perfectly fine tho : ), its just 104 lines longer.
*/

#include <stdio.h>

int main()
{
    int num;
    puts("Enter a valid hexadecimal number\n");
    scanf("%x", &num);
    printf("The decimal equivalent is %d\n", num); //literally the format specifier %d does the whole job.
    return 0;
}