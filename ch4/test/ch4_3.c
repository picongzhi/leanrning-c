#include <stdio.h>

int main(void) {
    float num;
    printf("Please enter a floating-point number: ");
    scanf("%f", &num);

    printf("%.1f\n", num);
    printf("%.2e\n", num);

    return 0;
}
