#include <stdio.h>

void Temperatures(double fahenheit);

int main(void) {
    double fahenheit;
    printf("Please enter fahenheit temperature(q to quit): ");
    while (scanf("%lf", &fahenheit) == 1) {
        Temperatures(fahenheit);
        printf("Please enter fahenheit temperature(q to quit): ");
    }
    printf("Bye!\n");

    return 0;
}

void Temperatures(double fahenheit) {
    const double const1 = 5.0;
    const double const2 = 9.0;
    const double const3 = 32.0;
    const double const4 = 273.16;

    double celcius = const1 / const2 * (fahenheit - const3);
    double kai = celcius + const4;

    printf("Fahrenheit temperature is %.2lf\n", fahenheit);
    printf("Celcius temperature is %.2lf\n", celcius);
    printf("Kai temperature is %.2lf\n", kai);
}
