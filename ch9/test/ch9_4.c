#include <stdio.h>

double hamonic(double a, double b);

int main(void) {
    double  x = 1.0, y = 2.0;
    printf("The hamonic mean of %.2lf and %.2lf is %.2lf.\n",
            x, y, hamonic(x, y));

    return 0;
}

double hamonic(double a, double b) {
    return 2 / (1 / a + 1 / b);
}
