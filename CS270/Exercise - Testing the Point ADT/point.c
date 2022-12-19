/* 
 * point.c
 * Implementation file for operations defined on the Point object
 */

/* Again, compiler directives go first */
/* Like import, #include brings in definitions needed to use these libraries */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "point.h"  // reads the Point type def file from current directory

/* Function definitions */

// struct Point *initPoint(char *label, int x, int y) {
//    struct Point *p;

//    p = (struct Point *) malloc(sizeof(struct Point));
//    // think about how we want handle this error if p is NULL

//    if (p==NULL){
//     printf("Malloc failed. Terminating the program.");
//     return NULL;
//    }

//    p->x = x;
//    p->y = y;
//    p->label = label;  // beware: subtle error here! (*p).label
//                       // can you think of a better way to initialize p->label?
//                     //  p->label = malloc(256);   //??
//                     //       strcpy(p->label, label); //??
        
//    return p;
// }

struct Point *initPoint(char *label, int x, int y) {
   struct Point *p;

   p = (struct Point *) malloc(sizeof(struct Point));

   if (p==NULL){
    printf("Malloc failed. Terminating the program.");
    return NULL;
   }

   p->x = x;
   p->y = y;

   p->label = malloc(256);
   memmove(p->label, label, 256); //deep copying label into struct's label field
   //difference between memmove and memcpy is that memcpy cannot handle memory overlap
   
   return p;

//I do not know if the following two lines free the memory while returning the expected pointer
  //  free(p); //deallocating space for struct p in the heap memory.
  //  p = NULL;

}

//This funciton, when given the address of an existing struct Point, frees the memory associated with its field label.
void freethespace(struct Point *p){
  free(p->label);
  p->label = NULL;
}



// readit is only here as a cautionary tale - DO NOT DO THIS
struct Point readit() {
  struct Point newpt;
  scanf("%d %d", &newpt.x, &newpt.y);
  scanf("%s", newpt.label);
  return newpt;
}

void readPoint(struct Point *p) {
  char label[11];       // limit label input to 10 chars (+ the nul-terminator)

  if (p== NULL)
  {
    p->label = NULL;
    return;
  }

  printf("%s", "\nEnter the label: ");
  getchar();  //eat newline
  scanf("%10s", label); // safety first!
  // NB: could try this instead
  // fgets(label, 10, stdin);
  printf("%s", "\nEnter x- and y-coordinates: ");
  scanf("%d %d", &(p->x), &(p->y));

  p->label = malloc(11);

  strcpy(p->label, label);

}

// computes the Euclidean distance between two points
double distance(struct Point a, struct Point b) {
   double result;
   double xpart, ypart;
   xpart = (a.x - b.x) * (a.x - b.x);
   ypart = (a.y - b.y) * (a.y - b.y);
   result = sqrt(xpart + ypart);
   return result;
}

void printPoint(struct Point p){
  printf("Point %s: [%d, %d]\n", p.label, p.x, p.y);   
}