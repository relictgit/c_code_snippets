#include "../header/sort_array.h"
#include <stdio.h>

short main_sort_array ()
{
  int array[] = {9, 5, 1, 3, 7, 4, 6};
  int size = sizeof (array) / sizeof (array[0]);

  for (int i = 0; i < size; i++)
  {
    printf ("elemen of unsorted array: %d\n", array[i]);
  }

  sort (array, size);
  print_array (array, size);

  return 0;
}

void sort (int array[], int size)
{
  // this is an example implementation of bubble sort
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if (array[j] > array[j + 1])
      {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
      /* to reverse the order of sorting the array run the following if
      statement if (array[j] < array[j + 1]) { int temp = array[j]; array[j] =
      array[j + 1]; array[j + 1] = temp;
      }
      */
    }
  }
}

void print_array (int array[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf ("index of sorted array: %d\n", array[i]);
  }
}
