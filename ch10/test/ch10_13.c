#include <stdio.h>

#define ROWS 3
#define COLS 5

void arr_input(double arr[][COLS], int rows);
double average_row(double arr[], int size);
double arr_average(double arr[][COLS], int rows);
double arr_max(double arr[][COLS], int rows);
void arr_show(double arr[][COLS], int rows);

int main(void) {
    int row;
    double arr[ROWS][COLS];
    
    arr_input(arr, ROWS);
    for (row = 0; row < ROWS; row++)
        printf("Average of row %d is %.2lf\n", row, average_row(arr[row], COLS));
    printf("Average of arr is %.2lf\n", arr_average(arr, ROWS));
    printf("Max of arr is %.2lf\n", arr_max(arr, ROWS));
    arr_show(arr, ROWS);

    return 0;
}

void arr_input(double arr[][COLS], int rows) {
    int r, c;
    printf("Please enter 3 group double number, 5 number every group\n");
    for (r = 0; r < rows; r++) {
        printf("Group %d:\n", r);
        for (c = 0; c < COLS; c++)
            scanf("%lf", &arr[r][c]);
    }
}

double average_row(double arr[], int size) {
    double total = 0.0;
    int r;
    for (r = 0; r < size; r++)
        total += arr[r];

    return total / size;
}

double arr_average(double arr[][COLS], int rows) {
   int r, c;
   double total = 0.0;
   for (r = 0; r < rows; r++)
       for (c = 0; c < COLS; c++)
           total += arr[r][c];
   
   return total / (rows * COLS);
}

double arr_max(double arr[][COLS], int rows) {
    int r, c;
    double max = arr[0][0];
    for (r = 0; r < rows; r++) {
        for (c = 0; c < COLS; c++) {
            if (max < arr[r][c])
                max = arr[r][c];
        }
    }

    return max;
}

void arr_show(double arr[][COLS], int rows) {
    int r, c;
    for (r = 0; r < rows; r++) {
        for (c = 0; c < COLS; c++)
            printf("%.2lf ", arr[r][c]);
        putchar('\n');
    }
}
