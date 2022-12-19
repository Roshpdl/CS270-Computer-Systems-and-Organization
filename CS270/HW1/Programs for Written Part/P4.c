
#include <stdio.h>

int main() {
    char c = '\1';
    short s = 2;
    int i = -21;
    float f = 6.5f;
    double d = 7.5;

    printf("%d\n", c * i);
    printf("%f\n", f / c);
    printf("%d\n", (int) f);
    printf("%g\n", d - s);
    printf("%d\n", i / s);

    return 0;
}
