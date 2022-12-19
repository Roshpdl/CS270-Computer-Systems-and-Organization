#include <stdio.h>
#include "event.h"

/*
 * This is the test program that tests the event.h and event.c
 * Author - Roshan Poudel
 */

int main(int argc, char *argv[])
{
    struct Event *e1, *e2;
    char name1[20], name2[20];
    int m1, d1, y1, m2, d2, y2;

//First event
    puts("Enter the name for the first event");
    scanf("%19s", name1);
    puts("Now enter the date of the event in format mm-dd-yyyy");
    scanf("%d-%d-%d", &m1, &d1, &y1);

//Second event
    puts("Similarly, Enter the name for the second event");
    scanf("%19s", name2);
    puts("Now enter the date of the event in format mm-dd-yyyy");
    scanf("%d-%d-%d", &m2, &d2, &y2);

//Initializing structs for two events    
    e1 = initEvent(name1, m1, d1, y1);
    e2 = initEvent(name2, m2, d2, y2);

//checking date conflicts
    if (checkConflict(e1, e2) == 0)
    {
        printEvent(e1);
        printEvent(e2);
    }

    else
    {
        puts("Both event occur on the same date. Please enter events without same date.");
    }

    bytesUsed(e1);


    return 0;
}