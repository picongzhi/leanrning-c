#include <stdio.h>

void swap(double *a, double *b);
void sort(double *a, double *b, double *c);

int main(void) {
    double x = 2.0, y = 3.0, z = 1.0;
    printf("Original x = %.2lf, y = %.2lf and z = %.2lf.\n",
            x, y, z);
    sort(&x, &y, &z);
    printf("Now x = %.2lf, y = %.2lf and z = %.2lf.\n",
            x, y, z);

    return 0;
}

void swap(double *a, double *b) {
    double temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(double *a, double *b, double *c) {
    if (*a > *b) 
        swap(a, b);
    if (*a > *c)
        swap(a, c);
    if (*b > *c)
        swap(b, c);
}
