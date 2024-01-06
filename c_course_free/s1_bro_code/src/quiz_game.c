#include "../header/quiz_game.h"
#include <ctype.h>
#include <stdio.h>

short main_quiz_game ()
{
    char questions[][100] = {
        "1. What year did the C language debut?: ", "2. Who is credited with creating C?: ",
        "3. What is the predecessor of C?: "};
    char options[][100] = {
        "A. 1969",
        "B. 1972",
        "C. 1975",
        "D. 1999",
        "A. Dennis Ritchie",
        "B. Nikola Tesla",
        "C. John Carmarck",
        "D. Doc Brown",
        "A. Objective C",
        "B. B",
        "C. C++",
        "D. C#"};
    char answers[3] = {'B', 'A', 'B'};
    int num_questions = sizeof (questions) / sizeof (questions[0]);
    char guess = 0;
    int score = 0;

    printf ("Quiz Game\n");

    for (int i = 0; i < num_questions; i++)
    {
        printf ("====================================\n");
        printf ("%s\n", questions[i]);
        printf ("====================================\n");
        for (int j = (i * 4); j < (i * 4) + 4; j++)
        {
            printf ("%s\n", options[j]);
        }
        printf ("guess: ");
        scanf ("%c",
               &guess); // \n is inside the input buffer, that needs to be flushed
        while ((getchar ()) != '\n')
            ; // remove the \n from the input buffer
        guess = toupper (guess);
        // normal use case of if else statements
        /* if (guess == answers[i]) {
          printf("correct\n");
          score++;
        } else {
          printf("wrong\n");
        } */
        // equivalent in ternary operator with multiple statements separated with
        // ","
        (guess == answers[i]) ? printf ("correct\n"), score++ : printf ("wrong\n");
    }
    printf ("final score: %d / %d\n", score, num_questions);

    return 0;
}
