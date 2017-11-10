#include <stdio.h>

int main(void) {
    int num;
    int even_cnt, odd_cnt;
    float even_total, odd_total;
    even_cnt = odd_cnt = 0;
    even_total = odd_total = 0.0f;

    printf("Please enter number (0 to quit): ");
    while (scanf("%d", &num) == 1 && num != 0) {
        if (num % 2 == 0) {
            even_cnt++;
            even_total += num;
        } else {
            odd_cnt++;
            odd_total += num;
        }
        printf("Please enter next number (0 to quit): ");
    }
    printf("Even count: %d, even average: %.2f\n",
            even_cnt, even_total / even_cnt);
    printf("Odd count: %d, odd average: %.2f\n",
            odd_cnt, odd_total / odd_cnt);
    
    return 0;
}
