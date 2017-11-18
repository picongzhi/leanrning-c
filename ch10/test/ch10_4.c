#include <stdio.h>

#define SIZE 10

int get_max_index(double *arr, int size);

int main(void) {
    double arr[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5, 10.2, 6.6, 7.7, 8.8, 9.9};
    printf("The max value index is %d\n", get_max_index(arr, SIZE));

    return 0;
}

int get_max_index(double *arr, int size) {
    int max_index = 0;
    int max_value = arr[0];
    int i;
    for (i = 1; i < size; i++) {
        if (arr[i] > max_value) {
            max_index = i;
            max_value = arr[i];
        }
    }

    return max_index;
}
