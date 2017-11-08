#include <stdio.h>

#define LEN 8

int main(void) {
    int i;
    int arr[LEN];
    printf("Please enter %d integer number: \n", LEN);
    for (i = 0; i < LEN; i++)
        scanf("%d", &arr[i]);
    for (i = LEN - 1; i >= 0; i--)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
