#include <stdio.h>

#define DAYS_OF_WEEK 7

int main(void) {
    int days;
    printf("Please enter days: ");
    scanf("%d", &days);
    
    while (days > 0) {
        printf("%d days are %d weeks, %d days.\n",
                days, days / DAYS_OF_WEEK, days % DAYS_OF_WEEK);
        printf("Please enter days: ");
        scanf("%d", &days);
    }
    printf("Done!\n");

    return 0;
}
