#include <stdio.h>

int main(void) {
    int num;
    int n, i;
    int isPrime;
    printf("Please enter a positive integer: ");
    scanf("%d", &num);

    for (n = 2; n < num; n++) {
        for (i = 2, isPrime = 1; i * i <= n; i++) {
            if (n % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime)
            printf("%d is prime.\n", n);
    }

    return 0;
}
