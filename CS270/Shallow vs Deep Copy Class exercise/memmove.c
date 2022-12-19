#include <stdio.h>
#include <assert.h>
#include <string.h>

int main() {
  int i, abc[] = {0, 1, 2};
  int *copy1, copy2[3];

  copy1 = abc;
  memmove(copy2, abc, sizeof(int)*3);

  abc[0] = 3;
  assert(copy1[0] == 3);
  assert(copy2[0] == 0);
  
  printf("All tests passed\n");
  
  printf("Original array abc:\n");
  for (i = 0; i < (sizeof(abc)/sizeof(abc[0])); i++) {
    printf("  abc[%d] = %d\n", i, abc[i]);
  }
  for (i = 0; i < (sizeof(abc)/sizeof(abc[0])); i++) {
    printf("  copy1[%d] = %d\n", i, copy1[i]);
  }
  for (i = 0; i < (sizeof(copy2)/sizeof(copy2[0])); i++) {
    printf("  copy2[%d] = %d\n", i, copy2[i]);
  }
}

//Here, contents of copy1 and copy2 are different because copy1 is a shallow copy of array abc and copy2 is a deep copy of abc.
//That means, whenever we change the value at index 0 in abc, the change appears in copy1 because copy1 is basically pointing to the the index 0.
//Whereas, using memmove() we deepcopy the entire array abc to copy2 making it independent of the abc. Therefore, changing the original array does not impact