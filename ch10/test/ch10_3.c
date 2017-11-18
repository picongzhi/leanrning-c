#include <stdio.h>

#define SIZE 10

int max(int *arr, int size);

int main(void) {
    int arr[SIZE] = {1, 3, 5, 7, 9, 10, 2, 4, 6, 8};
    printf("The max value is %d\n", max(arr, SIZE));

    return 0;
}

int max(int *arr, int size) {
    int i;
    int max = *arr;
    for (i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}
