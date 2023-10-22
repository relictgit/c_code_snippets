#include <stdio.h>
#include <stdlib.h>

int circle_circumference() {
  const double PI = 3.14159;
  double radius = 0.0;
  double circumference = 0.0;
  double area = 0.0;

  printf("\nEnter radius of a circle: ");
  scanf("%lf", &radius);

  circumference = 2 * PI * radius;
  area = PI * radius * radius;

  printf("circumference: %lf\n", circumference);
  printf("area: %lf\n", area);

  return 0;
}
