#include <stdio.h>

int main()
{
        int day1, month1, year1, hour1, min1;
        int day2, month2, year2, hour2, min2;

        printf("Gib das erste Datum im Format dd.mm.yyyy hh:mm an: ");
        scanf("%d.%d.%d %d:%d", &day1, &month1, &year1, &hour1, &min1);

        printf("Gib das zweite Datum im Format dd.mm.yyyy hh:mm an: ");
        scanf("%d.%d.%d %d:%d", &day2, &month2, &year2, &hour2, &min2);

        // Berechnung der Differenz in Stunden
        int totalMin1 = day1 * 1440 + month1 * 43800 + year1 * 525600 +
                        hour1 * 60 + min1;
        int totalMin2 = day2 * 1440 + month2 * 43800 + year2 * 525600 +
                        hour2 * 60 + min2;
        int diff = (totalMin2 - totalMin1) / 60;

        printf("Der Unterschied zwischen %02d.%02d.%04d %02d:%02d und %02d.%02d.%04d %02d:%02d beträgt %d Stunden.\n",
               day1, month1, year1, hour1, min1, day2, month2, year2, hour2,
               min2, diff);

        return 0;
}
