/*
 * event.c
 * Implementation file for the functions defined on the header file event.h
 * Author: Roshan Poudel
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "event.h"

struct Event *initEvent(char *title, int mm, int dd, int yyyy)
{
    struct Event *ptr;

    ptr = (struct Event *)malloc(sizeof(struct Event));
    if (ptr == NULL)
    {
        puts("Malloc failed. Terminating the Program\n"); // difference between puts and printf is puts() append the newline character to the thing it prints. Also, puts() cannot do format specifying.
        return NULL;
    }
    if (mm <= 12 && dd <= 31 && yyyy <= 9999)
    {
        ptr->month = mm; // can also write as (*ptr).month = mm;
        ptr->date = dd;
        ptr->year = yyyy;
    }
    ptr->name = malloc(sizeof(char) * 256);
    memmove(ptr->name, title, 256); // deep copying using memmove. memmove handles memory overlapping but memcpy doesn't. But, using memcpy is bit faster.

    return ptr;
}

int checkConflict(struct Event *a, struct Event *b)
{
    if ((a->month == b->month) && (a->date == b->date) && (a->year == b->year))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void printEvent(struct Event *a)
{
    printf("The name of the event is %s. It occurs on %2d/%2d/%4d.\n", a->name, a->month, a->date, a->year);
}

void freeEvent(struct Event *a)
{
    free(a->name);
    a->name = NULL;
}

int bytesUsed(struct Event *e){
    int bytes = (int) sizeof(e);
    if (e->name != NULL)
    {
        bytes = bytes + (int) sizeof(e->name);
    }
    printf("The bytes used is %d", bytes);
    return bytes;
}

