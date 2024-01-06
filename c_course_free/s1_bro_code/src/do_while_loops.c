#include "../header/do_while_loops.h"
#include <stdio.h>

short main_do_while_loop ()
{
    // while loop = checks a condition, THEN executes a block of code
    //              if the condition is true
    // do while loop = always execute a block of code onec, THEN
    //                 checks a condition

    int num = 0;
    int sum = 0;

    // The following while loop will check first the condition.
    // As for num being declaret to 0 it will jump out and does not
    // execute the code block
    /*while (num > 0) {
      printf("Enter a number greater 0: ");
      scanf("%d", &num);
      if (num > 0) {
        sum += num;
      }
    }*/

    // It looks differently when we look at the following code below.
    // Here the code block will be executed first and then the condition will be
    // checked.
    do
    {
        printf ("Enter a number greater 0: ");
        scanf ("%d", &num);
        if (num > 0)
        {
            sum += num;
        }
    } while (num > 0);

    printf ("sum: %d\n", sum);

    return 0;
}
