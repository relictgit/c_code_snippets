#include "../header/nested_loops.h"
#include <stdio.h>

short main_nested_loop ()
{
    // nested loops = a loop inside another loop

    int rows = 0;
    int columns = 0;
    char symbol;

    printf ("Enter # of rows: ");
    scanf ("%d", &rows);
    printf ("Enter # of columns: ");
    scanf ("%d", &columns);

    // getting rid of the \n character
    // scanf("%c"); -- error prone due to not putting an variable behind the
    // scanf("%c") is not a good practise
    // format specifier
    // nest practise can be found on geeksforgeeks
    // with the following best practise to flush the buffer
    // flushes the standard input
    // (clears the input buffer)
    while ((getchar ()) != '\n')
        ;

    printf ("Enter a symbol to use: ");
    scanf ("%c", &symbol);

    for (int i = 0; i <= rows; i++)
    {
        for (int j = 0; j <= columns; j++)
        {
            printf ("%c", symbol);
        }
        printf ("\n");
    }

    return 0;
}
