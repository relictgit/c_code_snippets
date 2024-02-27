#include <stdio.h>

int factorial(int num);

int main() {
    /* testing code */
    printf("0! = %i\n", factorial(0));
    printf("1! = %i\n", factorial(1));
    printf("3! = %i\n", factorial(3));
    printf("5! = %i\n", factorial(5));
}

/* define your function here (don't forget to declare it) */
int factorial(int num) {
    if(num == 0) {
        return num = 1;
    } else {
        return num *= factorial(num - 1);
    }
}
