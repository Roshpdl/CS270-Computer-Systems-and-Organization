/* 
 * point.h
 * Header file for defining the Point object and 
 * functions that operate on it
 */

// Point type definition
struct Point {
  char *label;
  int x, y;
};

// Function prototypes
struct Point *initPoint(char *, int, int);
void readPoint(struct Point *);
double distance(struct Point, struct Point);
void printPoint(struct Point);
void freethespace(struct Point *p);
