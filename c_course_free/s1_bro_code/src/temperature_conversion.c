#include "../header/temperature_conversion.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

short example_temperature_convertion ()
{
    char unit = 0;
    double temp = 0.0;

    printf ("Is the temperature in (F) or (C)?: ");
    scanf ("%c", &unit);

    unit = tolower (unit);

    switch (unit)
    {
    case 'c':
        printf ("Enter the temp in celsius: ");
        scanf ("%lf", &temp);
        temp = (temp * 9 / 5) + 32;
        printf ("The temperature in Farenheit is: %.1lf\n", temp);
        break;
    case 'f':
        printf ("Enter the temp in farenheit: ");
        scanf ("%lf", &temp);
        temp = ((temp - 32) * 5) / 9;
        printf ("The temperature in celsius is: %.1lf\n", temp);
        break;
    default:
        printf ("%c is not a valid input\n", unit);
        example_temperature_convertion ();
        break;
    }

    return 0;
}
