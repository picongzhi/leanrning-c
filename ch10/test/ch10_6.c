#include <stdio.h>

#define SIZE 10

void reverse(double *arr, int size);
void swap(double *a, double *b);
void show(double *arr, int size);

int main(void) {
    double arr[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
    printf("Originally:\n");
    show(arr, SIZE);
    reverse(arr, SIZE);
    printf("After reverse:\n");
    show(arr, SIZE);

    return 0;
}

void show(double *arr, int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%.2lf ", arr[i]);
    putchar('\n');
}

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(double *arr, int size) {
    int i;
    for (i = 0; i < size / 2; i++)
        swap(arr + i, arr + size - i - 1);
}
