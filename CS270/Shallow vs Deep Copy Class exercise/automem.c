#include <stdio.h>
#include <stdlib.h>

typedef struct powers {
  double base, square, cube;
} powers;

powers get_power(double in) {
  powers out = {.base = in,
		.square = in * in,
		.cube = in * in * in};
  return out;
}

int *get_even(int count) {
  int out[count];
  for (int i = 0; i < count; i++) {
    out[i] = 2*i;
  }
  return out;      // bad idea
}

//It is a bad idea because we are not returning an integer pointer to the array we created. Instead, the function
// just literally returns the address of the stack memory associated with the local variable 'out' which does not live 
//outside its function scope. That is the function is returning the address of the variable itself and not the address of its content/value.


//following code would solve the problem because now we are returning the pointer to the array we just created.
// int *get_even(int count){
//   int *out;
//   out = malloc((sizeof(int)* count));
//   for (int i = 0; i < count; i++){
//     out[i] = 2*i;
//   }
//   return out;
// }

int main() {
  powers threes = get_power(3);
  int *evens = get_even(3);
  printf("threes: %g\t%g\t%g\n", threes.base, threes.square, threes.cube);
  printf("evens: %i\t%i\t%i\n", evens[0], evens[1], evens[2]);
}
