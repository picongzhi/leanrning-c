#include <stdio.h>
#include <stdlib.h>

double power(double x, int n);

int main(int argc, char *argv[]) {
    char **end;
    double x;
    int n;

    if (argc != 3)
        puts("Usage: ./a.out x n");
    else {
        x = strtod(argv[1], end);
        n = atoi(argv[2]);
        printf("%.2lf power %d is %.2lf\n", x, n, power(x, n));
    }

    return 0;
}

double power(double x, int n) {
    double res = 1.0;
    int i = 0;

    while (i++ < n)
        res *= x;

    return res;
}
