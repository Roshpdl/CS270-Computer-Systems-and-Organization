#include <stdio.h>



// Function that convert Decimal to binary
void decToBinary(int n)
{
    // Size of an integer is assumed to be 32 bits
    for (int i = 31; i >= 0; i--) {
        int k = n >> i; // right shift
        if (k & 1) // helps us know the state of first bit
              printf("1");
        else printf("0");
    }
}


int main()
{

    // unsigned x;
    // scanf("%u", &x); //pass -101
    // printf("%u", x);

    // int a = -0; //two's complement of 0 is 0.
    // int b = 1;
    // printf("%d", a+b); //prints 1

    // int a = ~0; //inverts all the bits which, in 2's complement (signed form) is -1.
    // int b = 1;
    // printf("%d", a+b); //prints 0

//----------------------------------------
    
    int heckle, jeckle;
    unsigned thing[3];

    heckle = -1;
    // printf("%d\n", heckle >>31);
    // printf("%d\n", heckle & 0xFF);

    // thing[2] = heckle; //storing -1 to an unsigned variable
    // printf("%d\n", thing[2] >> 31);
    // printf("%d\n", ~thing[2]);

    thing[1] = 0;
    printf("%d\n", !!thing[1]);
    printf("%d\n", !~thing[1]);

    // jeckle = -5;
    // heckle = (jeckle << 3) + (jeckle << 1) - jeckle;
    // printf("%d\n", heckle);

    // int x = 5.0;
    // unsigned y = x;
    // printf("%d\n", x);
    // decToBinary(x);
    
    // puts("\n");
    // printf("\n%u\n", y);
    // decToBinary(y);

    // int x = -5;
    // int y, z;
    // y = ~x;
    // z = -x;
    // printf("%d\n%d\n", x, z);

    

    

    return 0;

}
