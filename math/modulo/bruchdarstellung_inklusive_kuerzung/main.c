#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s <bruch_zaehler> <bruch_nenner>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int bruch_zaehler = atoi(argv[1]);
    int bruch_nenner = atoi(argv[2]);
    short count_back;
    const short MIMINAL_DIV = 2;
    const short ZERO = 0;

    printf("now showing the calculation steps\n");
    printf("================================================\n");

    for(count_back = 100; count_back >= MIMINAL_DIV; count_back--) {
        while(bruch_zaehler % count_back == ZERO && bruch_nenner % count_back == ZERO) {
            printf(
                "bruch_zaehler: %d\t\tbruch_nenner: %d\t\tdivision by: %d\n", bruch_zaehler,
                bruch_nenner, count_back);
            bruch_zaehler /= count_back;
            bruch_nenner /= count_back;
        }
    }

    printf("\nnow showing the result\n");
    printf("================================================\n");
    printf("Bruch = %d/%d\n", bruch_zaehler, bruch_nenner);

    return 0;
}
