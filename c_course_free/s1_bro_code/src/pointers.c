#include "../header/pointers.h"
#include <stdio.h>

short main_pointers ()
{
    // pointer = a "variable-like" reference that holds a
    //           memory address to another variable, array, etc.
    //           some tasks are performed more easily with pointers
    //           * = indirection operator (value at address)

    /* Advantages of the pointer usage:
     * less time in program execution
     * working on the original variable
       (call by value ==> copy of variable, struct, array, etc)
     * With the help of pointers, we can create data structures
       (linked lists, stack, queue, b-trees)
     * returning more than one values from functions
     * searching and sorting large data very easily
     * dynamic memory allocation
     */

    int age = 21;
    // int *p_age = &age; // inizialisation and declaration in one go can be done,
    //                       but consider this below
    int *p_age = NULL; // good practise to assign NULL if declaring a pointer
    p_age = &age;      // then assign the address of
    printf ("address of age: %p\n", &age);
    printf ("value of age: %d\n", age);
    printf ("address of p_age: %p\n", p_age);
    printf ("value at stored address p_age: %d\n", *p_age);
    printf ("address of p_age (address of pointer): %p\n", &p_age);
    printf ("size of age: %lu\n", sizeof (age));
    printf ("size of p_age: %lu\n", sizeof (p_age));

    return 0;
}
