#include <stdio.h>

void to_base_n(unsigned long n, unsigned int base);

int main(void) {
    unsigned long number;
    unsigned int base;
    printf("Enter an integer number and an integer base  (q to quit):\n");
    while (scanf("%lu %d", &number, &base) == 2) {
        printf("%lu equal to: ", number);
        to_base_n(number, base);
        putchar('\n');
        printf("Enter an integer number and an integer base  (q to quit):\n");
    }
}

void to_base_n(unsigned long n, unsigned int base) {
    if (base <= 0)
        return;
    int r;

    r = n % base;
    if (n >= base)
        to_base_n(n / base, base);
    putchar('0' + r);

    return;
}
