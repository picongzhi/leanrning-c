#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

int main(void) {
    int i;
    int num[SIZE];
    int count[10];

    srand((unsigned int) time(0));
    for (i = 0; i < SIZE; i++)
        num[i] = rand() % 10 + 1;

    for (i = 0; i < SIZE; i++)
        count[num[i] - 1]++;

    for (i = 0; i < 10; i++)
        printf("%d occurs %d times.\n", i + 1, count[i]);

    return 0;
}
