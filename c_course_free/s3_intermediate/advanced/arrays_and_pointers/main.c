#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j;
    /* TODO: define the 2D pointer variable here */
    int **pnumbers;

    /* TODO: complete the following line to allocate memory for holding three rows */
    pnumbers = ( int ** ) malloc(3 * sizeof(int *)); // sizeof(int *) = 8 byte

    /* TODO: allocate memory for storing the individual elements in a row */
    pnumbers[0] = ( int * ) malloc(1 * sizeof(int)); // sizeof(int) = 4 byte
    pnumbers[1] = ( int * ) malloc(2 * sizeof(int));
    pnumbers[2] = ( int * ) malloc(3 * sizeof(int));

    pnumbers[0][0] = 1;
    pnumbers[1][0] = 1;
    pnumbers[1][1] = 1;
    pnumbers[2][0] = 1;
    pnumbers[2][1] = 2;
    pnumbers[2][2] = 1;

    for(i = 0; i < 3; i++) {
        for(j = 0; j <= i; j++) {
            printf("%d", pnumbers[i][j]);
        }
        printf("\n");
    }

    printf("sizeof(int): %lu\nsizeof(int *): %lu\n", sizeof(int), sizeof(int *));
    printf("sizeof(pnumbers): %lu\n", sizeof(pnumbers));
    printf("sizeof(pnumbers[0]): %lu\n", sizeof(pnumbers[0]));

    for(i = 0; i < 3; i++) {
        /* TODO: free memory allocated for each row */
        free(pnumbers[i]);
    }

    /* TODO: free the top-level pointer */
    free(pnumbers);

    return 0;
}
