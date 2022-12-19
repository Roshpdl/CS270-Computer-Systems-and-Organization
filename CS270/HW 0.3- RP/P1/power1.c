#include <stdio.h>
#include <math.h>

int main() 
{
    int base, exp;

    while (1)
    {
        printf("\nEnter the base number:\n");
        scanf("%d", &base);
        printf("\nEnter the index:\n");
        scanf("%d", &exp);
        if (exp >= 0 )
        {
            int result = pow(base, exp);
            printf("\nThe result is %d.\n", result);
        }
        else
        {
            printf("I am not doing negative exponents.\n");
            break;
        }
    }
    return 0;
}
