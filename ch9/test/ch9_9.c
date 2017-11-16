#include <stdio.h>

double power(double n, int p);
double do_power(double n, int p);

int main(void) {
    double x, xpow;
    int exp;

    printf("Enter a number and a integer power");
    printf(" to which\nthe number will be raised. Enter q");
    printf(" to quit.\n");
    while (scanf("%lf %d", &x, &exp) == 2) {
        xpow = power(x, exp);
        printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip -- bye!\n");

    return 0;
}

double power(double n, int p) {
    if (n == 0 || p == 0)
        return 0;
    
    int abs_p = p > 0 ? p : -p;
    double pow = 1;
    
    pow *= do_power(n, abs_p);

    return p > 0 ? pow : 1 / pow;
}

double do_power(double n, int p) {
    if (p > 1)
        return n * do_power(n, p - 1);
    else
        return n;
}
