#include <stdio.h>

void copy_ptrs(double *target, double *start, double *end);
void show_arr(double *arr, int size);

int main(void) {
    double target[3];
    double source[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    copy_ptrs(target, source + 2, source + 5);
    
    printf("Source array:\n");
    show_arr(source, 7);
    printf("Target array:\n");
    show_arr(target, 3);

    return 0;
}

void show_arr(double *arr, int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%.2lf ", arr[i]);
    putchar('\n');
}

void copy_ptrs(double *target, double *start, double *end) {
    while (start != end)
        *(target++) = *(start++);
}
