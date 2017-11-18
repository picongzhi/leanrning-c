#include <stdio.h>

#define ROWS 3
#define COLS 4

void copy_arr(double target[][COLS], double source[][COLS], int rows);
void show_arr(double arr[][COLS], int rows);

int main(void) {
    double source[][COLS] = {
        {1.1, 2.2, 3.3, 4.4},
        {2.2, 3.3, 4.4, 5.5},
        {3.3, 4.4, 5.5, 6.6}
    };
    double target[ROWS][COLS];
    copy_arr(target, source, ROWS);
    printf("Source array:\n");
    show_arr(source, ROWS);
    printf("Target array:\n");
    show_arr(target, ROWS);

    return 0;
}

void show_arr(double arr[][COLS], int rows) {
    int r, c;
    for (r = 0; r < rows; r++) {
        for (c = 0; c < COLS; c++)
            printf("%.2lf ", arr[r][c]);
        putchar('\n');
    }
}

void copy_arr(double target[][COLS], double source[][COLS], int rows) {
    int r, c;
    for (r = 0; r < rows; r++)
        for (c = 0; c < COLS; c++) 
            target[r][c] = source[r][c];
}
