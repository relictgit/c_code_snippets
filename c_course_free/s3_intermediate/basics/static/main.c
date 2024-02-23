#include <stdio.h>

/* todo
 * In this exercise, try to find the sum of some numbers by using the static keyword. Do not pass
 * any variable representing the running total to the sum() function. */

int sum(int num) {
    /**
     * find sum to n numbers
     */
    static int num_add = 0;
    num_add += num;
    return num_add;
}

int main() {
    printf("%d ", sum(55));
    printf("%d ", sum(45));
    printf("%d ", sum(50));
    return 0;
}
