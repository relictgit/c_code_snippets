#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int math_functions ()
{
    double a = sqrt (9);
    double b = pow (2, 4);
    int c = round (3.14);
    int d = ceil (3.14);
    int e = floor (3.14);
    int f = abs (-100);
    double g = log (3);
    double h = sin (45);
    double i = cos (45);
    double j = tan (45);

    printf ("square root of 9: %lf\n", a);
    printf ("base 2 power of 4: %lf\n", b);
    printf ("round 3.14: %d\n", c);
    printf ("ceil (always round up) of 3.14: %d\n", d);
    printf ("floor (always round down) of 3.14: %d\n", e);
    printf ("fabs(-100): %d\n", f);
    printf ("logarithm of 3 (log(3)): %lf\n", g);
    printf ("sinus of 45 is: %lf\n", h);
    printf ("cosinus of 45 is: %lf\n", i);
    printf ("tangenz of 45 is: %lf", j);

    return 0;
}
