#include <stdio.h>

int main(void) {
    float sum1, sum2;
    int times;
    int i;
    printf("Please enter times: ");
    scanf("%d", &times);
    
    sum1 = 0.0;
    sum2 = 0.0;
    for (i = 1; i <= times; i++) {
        sum1 += 1.0 / i;
        if (i % 2 == 0)
            sum2 -= 1.0 / i;
        else
            sum2 += 1.0 / i;
    }
    printf("Sum1 = %.2f\n", sum1);
    printf("Sum2 = %.2f\n", sum2);

    return 0;
}
