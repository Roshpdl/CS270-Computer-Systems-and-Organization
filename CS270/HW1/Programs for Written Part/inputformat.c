/* 
 *   Enforcing input formats
 */

#include <stdio.h>

int main() {
  int day, month, year;
  float amount;

  printf("Enter a date and the amount spent that day: ");
  scanf("%d/%d/%d $%g", &day, &month, &year, &amount);
  printf("On %d-%d-%d you spent $%.2f\n", day, month, year, amount);
  return 0;
}