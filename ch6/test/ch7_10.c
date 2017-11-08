#include <stdio.h>

int main(void) {
    int min, max;
    int i;
    long sum;
    printf("Enter lower and upper integer limits: ");
    while (scanf("%d %d", &min, &max) == 2 && min < max) {
        sum = 0;
        for (i = min; i <= max; i++)
            sum += i * i;
        printf("The sums of the squares from %ld to %ld is %ld\n",
                (long) min * min, (long) max * max, sum);
        printf("Enter next set of limits: ");
    }
    printf("Done!\n");

    return 0;
}
