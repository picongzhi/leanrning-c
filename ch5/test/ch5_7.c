#include <stdio.h>

double cube(double num);

int main(void) {
    double num;
    printf("Please enter a double number: ");
    scanf("%lf", &num);
    printf("cube of %.2lf is %.2lf\n",
            num, cube(num));

    return 0;
}

double cube(double num) {
    return num * num * num;
}
