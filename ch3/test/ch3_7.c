#include <stdio.h>

int main(void) {
    float trans = 2.54f;
    float height;
    printf("Enter your height(inch): ");
    scanf("%f", &height);
    printf("Your height is %f (cm)\n", trans * height);

    return 0;
}
