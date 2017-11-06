#include <stdio.h>

#define MIN_TO_HOUR 60

int main(void) {
    int min;
    printf("Please enter minutes(<=0 to quit): ");
    scanf("%d", &min);
    while (min > 0) {
        printf("%d is %d hours and %d minutes.\n",
                min, min / MIN_TO_HOUR, min % MIN_TO_HOUR);
        printf("Please enter minutes(<=0 to quit): ");
        scanf("%d", &min);
    }
    printf("Done!\n");

    return 0;
}
