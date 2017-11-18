#include <stdio.h>

#define ROWS 3
#define COLS 5

void show_arr(int arr[][COLS], int rows);
void multi_arr(int arr[][COLS], int rows);

int main(void) {
    int arr[ROWS][COLS] = {
        {1, 2, 3, 4, 5},
        {2, 3, 4, 5, 6},
        {3, 4, 5, 6, 7}
    };
    printf("Original array: \n");
    show_arr(arr, ROWS);
    multi_arr(arr, ROWS);
    printf("After multi: \n");
    show_arr(arr, ROWS);
    
    return 0;
}

void multi_arr(int arr[][COLS], int rows) {
    int r, c;
    for (r = 0; r < rows; r++)
        for (c = 0; c < COLS; c++)
            arr[r][c] *= 2;
}

void show_arr(int arr[][COLS], int rows) {
    int r, c;
    for (r = 0; r < rows; r++) {
        for (c = 0; c < COLS; c++)
            printf("%d ", arr[r][c]);
        putchar('\n');
    }
}
