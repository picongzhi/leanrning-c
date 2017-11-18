#include <stdio.h>

#define SIZE 10

double sub_max_min(double *arr, int size);

int main(void) {
    double arr[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5, 10.1, 6.6, 7.7, 8.8, 9.9};
    printf("The max value subtract min value is %.2lf\n", sub_max_min(arr, SIZE));

    return 0;
}

double sub_max_min(double *arr, int size) {
    int min, max;
    min = max = arr[0];
    int i;
    for (i = 1; i < size; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    return max - min;
}
