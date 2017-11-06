#include <stdio.h>

int main(void) {
    int days;
    int current = 0;
    int total = 0;
    int i = 1;

    printf("Please enter days: ");
    scanf("%d", &days);
    
    if (days <= 0) {
        printf("Invalud input!\n");
        return 1;
    }
    while (i <= days) {
        current = i;
        total = total + current;
        i++;
    }
    printf("Total %d\n", total);

    return 0;
}
