#include <assert.h>
#include <stdio.h>

typedef struct
{
  int a, b;
  double c, d;
  int *efg;
} demo_s;

int main()
{
  demo_s d1 = {.b = 1, .c = 2, .d = 3, .efg = (int[]){4, 5, 6}};
  demo_s d2 = d1;

  d1.b = 13;
  d1.c = 41;
  d1.efg[0] = 7;

  printf("Printing all the contents of struct d1\n");
  printf("%d\n", d1.a);
  printf("%d\n", d1.b);
  printf("%lf\n", d1.c);
  printf("%lf\n", d1.d);

  for (int i = 0; i < 3 ; i++)
  {
    printf("%d\n", d1.efg[i]);
  }

  printf("Printing all the contents of struct d2\n");
  printf("%d\n", d2.a);
  printf("%d\n", d2.b);
  printf("%lf\n", d2.c);
  printf("%lf\n", d2.d);

  for (int j = 0; j < 3 ; j++)
  {
    printf("%d\n", d2.efg[j]);
  }

  assert(d2.a == 0);
  assert(d2.b == 1);
  assert(d2.c == 2);
  assert(d2.d == 3);
  assert(d2.efg[0] == 7);
  printf("All tests passed.\n");
  return 0;
}