#include "../header/logical_operators.h"
#include <stdbool.h>
#include <stdio.h>

short logical_not ()
{
    // logical operators
    // --> ! (NOT) reverses the state of a condition

    bool sunny = true;

    // if (sunny == true /* equivalens: sunny | sunny == ture | sunny == 1 */) {
    if (! sunny)
    {
        printf ("it is cloudy outside\n");
    }
    else
    {
        printf ("it is sunny outside\n");
    }

    return 0;
}
