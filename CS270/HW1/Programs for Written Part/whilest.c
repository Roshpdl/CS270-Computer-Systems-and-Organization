#include <stdio.h>

int main() {

    int i = 10;
    // for (i = 10; i>=1; i/=2) {
    //     printf("%d", i++);
    // }
    while (i >= 1)
    {
        printf("%d", i++);
        i/=2;
    }
    return 0;
}

