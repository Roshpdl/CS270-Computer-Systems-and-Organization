/*
Author : Roshan Poudel
Homework 4 Programming part
Question 1
October 27, 2022
PS: This code contains lengthy comments for my own understanding.
*/


#include <stdio.h>

int is_neg(int);
int is_pos(int);

int main()
{

    int num ;
    int result_isneg, result_ispos;

    printf("Enter a number\n");
    scanf("%d", &num);
    result_isneg = is_neg(num);
    result_ispos = is_pos(num);

    if (result_isneg == 1 && result_ispos == 0)
    {
        printf("The number is negative\n");
    }
    else if (result_isneg == 0 && result_ispos == 1)
    {
        printf("The number is positive\n");
    }

    else
    {
        printf("Incosistent values from the functions. Check them!\n");
    }

    return 0;
}

int is_neg(int x)
{
    int bit_length = (sizeof(x) * 8) -1 ; // 1byte = 8bits. So, int stores 4 bytes. That means it holds 4*8 = 32 bits. //Subtracting 1 to let MSB (that represents the sign) stay.
    x = x >> bit_length;    //Negative numbers are stored in two's complement form. // Also, arithmetic right shift is being performed with signed bits.
    x = x & 1;                      // After this operation, x = 1 if the number is negative and x = 0 otherwise.
    return x;
}

int is_pos(int x)
{
    int bit_length = (sizeof(x) * 8) - 1;
    x = x >> bit_length;
    // x = x & 1; //Returns either 1 or 0;
    // x = x ^ 1; //To convert integer 0 to 1 and vice versa we XOR with integer 1. NOT BY INVERTING BITS!

    //Alternative wierd way to convert 1 to 0 and 0 to 1.  Starting from line 56 instead of using XOR, we proceed as follows:
    // x = ~(-x);
    // x = -x;

    //Dr.Carl's way to do it, So, after line 54, 
    //just add 1 to x and the program works fine, 
    //because after shifting 31 to the right, the only thing that remains is 
    //either -1 (0b11111...1 -> in case of negative integers) or 0 (0b00000...0 -> in case of positive integers).
    x += 1;
    return x;
}