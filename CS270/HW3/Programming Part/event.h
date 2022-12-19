/*
 * event.h
 * Header file for defining the Event object and
 * functions that operate on it
 */

// Event type definition
struct Event
{
   char *name;
   int month, date, year;
} event;

struct Event *initEvent(char *, int, int, int);
int checkConflict(struct Event *, struct Event *);
void printEvent(struct Event *);
void freeEvent(struct Event *);
int bytesUsed(struct Event *e);