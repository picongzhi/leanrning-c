#include <stdio.h>

void fibonacci(unsigned int n);

int main(void) {
    unsigned int n;

    printf("Please enter a positive integer: ");
    scanf("%d", &n);
    fibonacci(n);

    return 0;
}

void fibonacci(unsigned int n) {
    int a = 1, b = 1;
    int temp;
    unsigned int i;

    for (i = 0; i < n; i++) {
        if (i < 1)
            printf("%d ", a);
        else {
            temp = b;
            b = a + b;
            a = temp;
            printf("%d ", a);
        }
    }
    printf("\n");
}
