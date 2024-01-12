#include "../header/calculator.h"
#include <stdio.h>
#include <stdlib.h>

short example_calculator ()
{
  char operator= 0;
  double num1 = 0.0;
  double num2 = 0.0;
  double result = 0.0;

  printf ("Enter an operator (+ - / *): ");
  scanf ("%c", &operator);

  switch (operator)
  {
  case '+':
    printf ("Enter the values for num1 and num2 (<num1> <num2> or "
            "<num1>\\n<num2>): ");
    scanf ("%lf %lf", &num1, &num2);
    result = num1 + num2;
    printf ("the result of %.2lf + %.2lf = %.2lf\n", num1, num2, result);
    break;
  case '-':
    printf ("Enter the values for num1 and num2 (<num1> <num2> or "
            "<num1>\\n<num2>): ");
    scanf ("%lf %lf", &num1, &num2);
    result = num1 - num2;
    printf ("the result of %.2lf - %.2lf = %.2lf\n", num1, num2, result);
    break;
  case '*':
    printf ("Enter the values for num1 and num2 (<num1> <num2> or "
            "<num1>\\n<num2>): ");
    scanf ("%lf %lf", &num1, &num2);
    result = num1 * num2;
    printf ("the result of %.2lf * %.2lf = %.2lf\n", num1, num2, result);
    break;
  case '/':
    printf ("Enter the values for num1 and num2 (<num1> <num2> or "
            "<num1>\\n<num2>): ");
    scanf ("%lf %lf", &num1, &num2);
    if (num2 == 0)
    {
      printf ("You are about to calculate division by 0. This is impossible\n");
      printf ("0 is taken as invalid input, consider a different number!\n");
      example_calculator ();
    }

    else
    {
      result = num1 / num2;
      printf ("the result of %.2lf / %.2lf = %.2lf\n", num1, num2, result);
    }
    break;
  default:
    printf ("%c is not a valid input, try again!\n", operator);
    example_calculator ();
    break;
  }

  return 0;
}
