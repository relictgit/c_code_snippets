#include <stdio.h>

int main()
{
  int day1 = 0;
  int month1 = 0;
  int year1 = 0;
  int hour1 = 0;
  int min1 = 0;
  int day2 = 0;
  int month2 = 0;
  int year2 = 0;
  int hour2 = 0;
  int min2 = 0;
  double diff = 0.0;
  double totalMin1 = 0.0;
  double totalMin2 = 0.0;

  printf("Gib das erste Datum im Format dd.mm.yyyy hh:mm an: ");
  scanf("%d.%d.%d %d:%d", &day1, &month1, &year1, &hour1, &min1);

  printf("Gib das zweite Datum im Format dd.mm.yyyy hh:mm an: ");
  scanf("%d.%d.%d %d:%d", &day2, &month2, &year2, &hour2, &min2);

  // Berechnung der Differenz in Stunden
  totalMin1 = day1 * 1440 + month1 * 43800 + year1 * 525600 + hour1 * 60 +
        min1;
  totalMin2 = day2 * 1440 + month2 * 43800 + year2 * 525600 + hour2 * 60 +
        min2;
  diff = (totalMin2 - totalMin1) / 60;

  printf("Der Unterschied zwischen \n--> %02d.%02d.%04d %02d:%02d Uhr \n--> %02d.%02d.%04d %02d:%02d Uhr \n beträgt %.2f Stunden.\n",
         day1, month1, year1, hour1, min1, day2, month2, year2, hour2,
         min2, diff);

  return 0;
}
