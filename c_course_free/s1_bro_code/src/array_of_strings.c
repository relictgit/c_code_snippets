#include "../header/array_of_strings.h"
#include <stdio.h>
#include <string.h>

short main_array_of_strings ()
{
    char cars[][10] = {"Mustang", "Audi", "Lada"};

    // cars[0] = "Tesla";
    strcpy (cars[0], "Tesla");

    for (unsigned int i = 0; i < sizeof (cars) / sizeof (cars[0]); i++)
    {
        printf ("%s\n", cars[i]);
    }

    return 0;
}
