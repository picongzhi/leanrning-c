#include <stdio.h>

#define ROWS 3
#define COLS 5

void copy_arr(int rows, int cols, double target[rows][cols], double source[rows][cols]);
void show_arr(int rows, int cols, double arr[rows][cols]);

int main(void) {
    double source[ROWS][COLS] = {
        {1.1, 2.2, 3.3, 4.4, 5.5},
        {2.2, 3.3, 4.4, 5.5, 6.6},
        {3.3, 4.4, 5.5, 6.6, 7.7}
    };
    double target[ROWS][COLS];

    copy_arr(ROWS, COLS, target, source);
    show_arr(ROWS, COLS, target);

    return 0;
}

void show_arr(int rows, int cols, double arr[rows][cols]) {
    int r, c;
    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++)
            printf("%.2lf ", arr[r][c]);
        putchar('\n');
    }
}

void copy_arr(int rows, int cols, double target[rows][cols], double source[rows][cols]) {
    int r, c;
    for (r = 0; r < rows; r++)
        for (c = 0; c < cols; c++)
            target[r][c] = source[r][c];
}
