/* todo
 * Declare grades as a two-dimensional array of integers
 * Complete the for loops by specifying their terminating conditions
 * Compute the average marks obtained in each subject */

#include <stdio.h>

int main() {
    /* TODO: declare the 2D array grades here */
    const int row = 2;
    const int column = 5;
    int grades[row][column];

    float average;
    int i;
    int j;

    grades[0][0] = 80;
    grades[0][1] = 70;
    grades[0][2] = 65;
    grades[0][3] = 89;
    grades[0][4] = 90;

    grades[1][0] = 85;
    grades[1][1] = 80;
    grades[1][2] = 80;
    grades[1][3] = 82;
    grades[1][4] = 87;

    /* TODO: complete the for loop with appropriate terminating conditions */
    for(i = 0; i < row; i++) {
        average = 0;
        for(j = 0; j < column; j++) {
            average += grades[i][j];
        }

        /* TODO: compute the average marks for subject i */
        average /= column;
        printf("The average marks obtained in subject %d is: %.2f\n", i, average);
    }

    return 0;
}
