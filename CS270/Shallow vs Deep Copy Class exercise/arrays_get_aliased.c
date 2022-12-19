#include <assert.h>
#include <stdio.h>

int main()
{
  int i;
  int abc[] = {0, 1, 2};
  int *copy = abc;

  // Before the statement copy[0] = 3, the values of both abc and copy are same. That is {0, 1, 2}

  copy[0] = 3;
  assert(abc[0] == 3);
  printf("All tests passed\n");

  // After the statement copy[0] = 3, however, the value of both abc and copy changes. That is {3, 1, 2}

  printf("Original array abc:\n");
  printf("  sizeof array: %ld, sizeof element: %ld\n", sizeof(abc), sizeof(abc[0]));
  for (i = 0; i < 3; i++)
  {
    printf("  abc[%d] = %d\n", i, abc[i]);
  }
  for (i = 0; i < 3; i++)
  {
    printf("  copy[%d] = %d\n", i, copy[i]);
  }
}
