#include "../header/swap_values.h"
#include <stdio.h>
#include <string.h>

short main_swap_values ()
{
    char x = 'X';
    char y = 'Y';
    char temp_chars;

    // swapping process with char symbols
    temp_chars = x;
    x = y;
    y = temp_chars;

    printf ("x contains: %c\ny contains: %c\n", x, y);

    // swap process using character arrays (strings)
    // there can be buffer overflows once character arrays have not the same size
    // there are unexpected behaviourse like in case of
    // char glas_one[] = "water";
    // char glas_two[] = "lemonade";
    // after swapping glas one contains: lemonawater
    // and the second glas contains: water
    // this will happen with the folowing code below
    char glas_one[] = "water";
    char glas_two[] = "lemonade";
    char temp_string[15];
    strcpy (temp_string, glas_one);
    strcpy (glas_one, glas_two);
    strcpy (glas_two, temp_string);
    printf ("first glas contains = %s\nsecond glas contains = %s\n", glas_one, glas_two);

    // to prevent this unexpected behaviour, you can take the following steps
    // Method 1
    char glas_one_second_try[15] = "water";
    char glas_two_second_try[15] = "lemonade";
    char temp_string_second_try[15];
    strcpy (temp_string_second_try, glas_one_second_try);
    strcpy (glas_one_second_try, glas_two_second_try);
    strcpy (glas_two_second_try, temp_string_second_try);
    printf (
        "first glas contains = %s\nsecond glas contains = %s\n", glas_one_second_try,
        glas_two_second_try);

    return 0;
}
