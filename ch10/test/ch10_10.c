#include <stdio.h>

#define SIZE 4

void arr_add(int *arr1, int *arr2, int *arr3, int size);
void show_arr(int *arr, int size);

int main(void) {
    int arr1[SIZE] = {2, 4, 5, 8};
    int arr2[SIZE] = {1, 0, 4, 6};
    int arr3[SIZE];

    arr_add(arr1, arr2, arr3, SIZE);
    show_arr(arr1, SIZE);
    show_arr(arr2, SIZE);
    show_arr(arr3, SIZE);

    return 0;
}

void show_arr(int *arr, int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    putchar('\n');
}

void arr_add(int *arr1, int *arr2, int *arr3, int size) {
    int i;
    for (i = 0; i < size; i++)
        arr3[i] = arr1[i] + arr2[i];
}
