#include "../header/hypotenuse_calculator.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

short hypotenuse ()
{
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    printf ("We have a triangle\n");
    printf ("           '           \n");
    printf ("          / \\         \n");
    printf ("         /   \\           \n");
    printf ("     b  /     \\ a             \n");
    printf ("       /       \\               \n");
    printf ("      /         \\               \n");
    printf ("      -----------\n");
    printf ("           c        \n");

    printf ("Enter the length of side a: ");
    scanf ("%lf", &a);
    printf ("Enter the length of side b: ");
    scanf ("%lf", &b);

    c = sqrt (a * a + b * b);

    printf ("the hypotenuse of c is: %lf\n", c);

    return 0;
}
