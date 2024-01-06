#include "../header/structs.h"
#include <stdio.h>
#include <string.h>

short main_struct ()
{
    // structs = collection of related members ("variables")
    //           they can be of different data types
    //           listed under one name in a block of memory
    //           VERY SIMILAR to classes in other languages (but no methods)

    struct player p1;
    struct player p2;

    // initialization of the members
    // method 1
    strcpy (p1.name, "kevin");
    p1.score = 32;

    strcpy (p2.name, "bro");
    p2.score = 31;

    // method 2 containing deklaration and initialization in one line
    /* struct player p3 = {"Mike", 80}; */

    printf ("Player one: %s has score: %d\n", p1.name, p1.score);
    printf ("Player two: %s has score: %d\n", p2.name, p2.score);

    return 0;
}
