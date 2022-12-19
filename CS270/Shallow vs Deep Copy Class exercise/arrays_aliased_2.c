#include <assert.h>
#include <stdio.h>

int main() {
  int i;
  int abc[] = {0, 1, 2};
  int *copy = abc;

  copy[0] = 3;
  assert(abc[0] == 3);
  printf("All tests passed\n");
  
  printf("Original array abc:\n");
  for (i = 0; i < (sizeof(abc)/sizeof(abc[0])); i++) {
    printf("  abc[%d] = %d\n", i, abc[i]);
  }
  for (i = 0; i < (sizeof(abc)/sizeof(abc[0])); i++) {
    printf("  copy[%d] = %d\n", i, copy[i]);
  }
}

// sizeof(abc) = 12 (total size of the array)
// sizeof(abc[0]) = 4 (size of one element in the array)
// total size/ size of one elements gives the total length of the array.