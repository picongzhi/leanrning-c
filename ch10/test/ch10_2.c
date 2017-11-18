#include <stdio.h>

#define SIZE 5

void copy_arr(double target[], const double source[], int size);
void copy_ptr(double *target, const double *source, int size);
void copy_ptrs(double *target, double *start, double *end);
void show_arr(const double *arr, int size);

int main(void) {
    double source[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[SIZE];
    double target2[SIZE];
    double target3[SIZE];

    copy_arr(target1, source, SIZE);
    copy_ptr(target2, source, SIZE);
    copy_ptrs(target3, source, source + SIZE);

    show_arr(source, SIZE);
    show_arr(target1, SIZE);
    show_arr(target2, SIZE);
    show_arr(target3, SIZE);

    return 0;
}

void show_arr(const double *arr, int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%lf ", arr[i]);
    printf("\n");
}

void copy_ptrs(double *target, double *start, double *end) {
    while (start != end) 
        *(target++) = *(start++);
}

void copy_ptr(double *target, const double *source, int size) {
    int i;
    for (i = 0; i < size; i++)
        *(target + i) = *(source + i);
}

void copy_arr(double target[], const double source[], int size) {
    int i;
    for (i = 0; i < size; i++)
        target[i] = source[i];
}
