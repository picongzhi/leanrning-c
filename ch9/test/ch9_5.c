#include <stdio.h>

void large_of(double *a, double *b);

int main(void) {
    double x = 1.0, y = 2.0;
    printf("Originally x = %.2lf and y = %.2lf.\n", x, y);
    large_of(&x, &y);
    printf("Now x = %.2lf and y = %.2lf.\n", x, y);

    return 0;
}

void large_of(double *a, double *b) {
    double max = (*a > *b) ? *a : *b;
    *a = *b = max;
}
