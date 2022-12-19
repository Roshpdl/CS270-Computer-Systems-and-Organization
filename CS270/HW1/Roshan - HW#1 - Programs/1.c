/*   
  *  HW01 - Programming Problem 1
  *  Roshan Poudel
  */

#include <stdio.h>

int main() {

    int day, month, year;

    scanf("%d/%d/%d", &month, &day, &year);
    printf("You entered the date %.4d-%.2d-%.2d\n", year, month, day);

    return 0;
}