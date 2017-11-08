#include <stdio.h>

int main(void) {
    int year = 0;
    const double init = 100.0;
    const double daphne_rate = 0.1;
    const double deirdre_rate = 0.05;
    double daphne_total = init;
    double deirdre_total = init;

    while (daphne_total >= deirdre_total) {
        daphne_total += init * daphne_rate;
        deirdre_total = deirdre_total * (1 + deirdre_rate);
        year++;
    }
    printf("It takes %d years.\n", year);
    printf("And Daphne has %.2lf dollars, Deirdre has %.2lf dollars.\n",
            daphne_total, deirdre_total);

    return 0;
}
