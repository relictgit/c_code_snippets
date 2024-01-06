#include "../header/for_loops.h"
#include <stdio.h>

short main_for_loop ()
{
    // for loop = repeats a section of code a limited amount of times
    // for loops are also known as counting loops

    for (int i = 0; i < 10; i++)
    {
        printf ("the index is: %d\n", i);
    }

    return 0;
}
