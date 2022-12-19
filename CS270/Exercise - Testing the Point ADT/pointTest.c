#include <stdio.h>
#include "point.h"   // required to get the definition of Point

/* 
 * All executable C programs require a main function 
 * as it always executed first;
 * this one runs a simple test of our Point functionality
 */

int main(int argc, char *argv[]) {

  // the arguments argc and argv above are used with the command line
  // and are required for main

  // define two Point objects
  struct Point p1, p2;
 
  char name[20];
  printf("Enter your first name: ");
  scanf("%19s", name);
  printf("Hey there, %s\n", name);


  // read in (and display) information for each point
  readPoint(&p1);
  printPoint(p1);

  readPoint(&p2);
  printPoint(p2);


  // compute the distance between the points
  double dist = distance(p1, p2);
  printf("\nDistance = %f\n", dist);

 
  freethespace(&p1);
  freethespace(&p2);

  
  
// Code to test the init function

// struct Point *p1, *p2;

// p1 = initPoint("Pokhara", 20, 20);
// p2 = initPoint("Kathmandu", 20, 30);

// printPoint(*p1);
// printPoint(*p2);

// double dist = distance(*p1, *p2);
// printf("\nDistance = %f\n", dist);



  return 0;
}



