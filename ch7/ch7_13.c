#include <stdio.h>

#define SIZE 8

double power(double n, int exp);

int main(void) {
    int i;
    int arr[SIZE];

    for (i = 0; i < SIZE; i++)
        arr[i] = (int) power(2, i);

    i = 0;
    do {
        printf("%d ", arr[i]);
        i++;
    } while (i < SIZE);
    printf("\n");

    return 0;
}

double power(double n, int exp) {
    double res = 1.0;
    int i;
    for (i = 0; i < exp; i++)
        res *= n;
    return res;
}
