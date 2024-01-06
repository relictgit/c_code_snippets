#include "../header/read_file.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

short main_read_file ()
{
    FILE *fptr = NULL;
    char buffer[300] = "";
    int buffer_size = sizeof (buffer) / sizeof (buffer[0]);

    if ((fptr = fopen ("test.txt", "r")) == NULL)
    {
        fprintf (stderr, "Could not open file!\nErrorcode is: %s\n", strerror (errno));
        exit (EXIT_FAILURE);
    }
    else
    {
        while ((fgets (buffer, buffer_size, fptr)) != NULL)
        {
            printf ("%s\n", buffer);
        }
        fclose (fptr);
    }

    return 0;
}
