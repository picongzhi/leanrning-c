#include <stdio.h>

int main(void) {
    int min, max;
    int i;
    printf("Please enter the min and max value: ");
    scanf("%d %d", &min, &max);
    
    for (i = min; i <= max; i++) 
        printf("%d %ld %ld\n", 
                i, (long) i * i, (long) i * i * i);

    return 0;
}
