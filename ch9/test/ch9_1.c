#include <stdio.h>

double min(double a, double b);

int main(void) {
    double x = 1.0, y = 2.0;
    printf("The minimum value of %.2lf and %.2lf is %.2lf\n",
            x, y, min(x, y));

    return 0;
}

double min(double a, double b) {
    return a < b ? a : b;
}
