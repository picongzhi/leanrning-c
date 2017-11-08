#include <stdio.h>

float res(float first, float second);

int main(void) {
    float first, second;
    printf("Please enter two floating number: ");
    while (scanf("%f %f", &first, &second) == 2) {
        printf("(%.2f - %.2f) / (%.2f * %.2f) = %.2f\n",
                first, second, first, second, res(first, second));
    }
    printf("Finished!\n");

    return 0;
}

float res(float first, float second) {
    return (first - second) / (first * second);
}
