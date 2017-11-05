#include <stdio.h>

#define GAS_TRANS 3.785
#define DIS_TRANS 1.609

int main(void) {
    float mileage;
    float gas;

    printf("Please enter mileage(mile): ");
    scanf("%f", &mileage);
    printf("Please enter gas(gallon): ");
    scanf("%f", &gas);

    printf("miles every gallon: %.1f\n", mileage / gas);
    printf("pint every 100 kilometers: %.1f\n", (GAS_TRANS * gas) / (100 * DIS_TRANS * mileage));

    return 0;
}
