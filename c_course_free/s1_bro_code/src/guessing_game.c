#include "../header/guessing_game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

short main_guessing_game ()
{
    const int MIN = 1;
    const int MAX = 100;
    int guess = 0;
    int guesses = 0;
    int answer = 0;

    // uses current time as a seed
    srand (time (0));

    // generate a rand number between MIN and MAX
    answer = (rand () % MAX) + MIN;

    /* printf("answer is: %d\n", answer); */

    do
    {
        printf ("Ener a guess: ");
        scanf ("%d", &guess);
        if (guess > answer)
        {
            printf ("guess: %d --- is to high\n", guess);
        }
        else if (guess < answer)
        {
            printf ("guess: %d --- is to low\n", guess);
        }
        else
        {
            printf ("CORRECT!\n");
        }
        guesses++;
    } while (guess != answer);

    printf ("===========================================\n");
    printf ("answer: %d\n", answer);
    printf ("guesses: %d\n", guesses);
    printf ("===========================================\n");

    return 0;
}
