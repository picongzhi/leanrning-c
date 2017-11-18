#include <stdio.h>

#define ROWS 3
#define COLS 5

void arr_input(int rows, int cols, double arr[rows][cols]);
double average_row(int size, double arr[size]);
double arr_average(int rows, int cols, double arr[rows][cols]);
double arr_max(int rows, int cols, double arr[rows][cols]);
void arr_show(int rows, int cols, double arr[rows][cols]);

int main(void) {
    int row;
    double arr[ROWS][COLS];
    
    arr_input(ROWS, COLS, arr);
    for (row = 0; row < ROWS; row++)
        printf("Average of row %d is %.2lf\n", row, average_row(ROWS, arr[row]));
    printf("Average of arr is %.2lf\n", arr_average(ROWS, COLS, arr));
    printf("Max of arr is %.2lf\n", arr_max(ROWS, COLS, arr));
    arr_show(ROWS, COLS, arr);

    return 0;
}

void arr_input(int rows, int cols, double arr[rows][cols]) {
    int r, c;
    printf("Please enter 3 group double number, 5 number every group\n");
    for (r = 0; r < rows; r++) {
        printf("Group %d:\n", r);
        for (c = 0; c < cols; c++)
            scanf("%lf", &arr[r][c]);
    }
}

double average_row(int size, double arr[size]) {
    double total = 0.0;
    int r;
    for (r = 0; r < size; r++)
        total += arr[r];

    return total / size;
}

double arr_average(int rows, int cols, double arr[rows][cols]) {
   int r, c;
   double total = 0.0;
   for (r = 0; r < rows; r++)
       for (c = 0; c < cols; c++)
           total += arr[r][c];
   
   return total / (rows * cols);
}

double arr_max(int rows, int cols, double arr[rows][cols]) {
    int r, c;
    double max = arr[0][0];
    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            if (max < arr[r][c])
                max = arr[r][c];
        }
    }

    return max;
}

void arr_show(int rows, int cols, double arr[rows][cols]) {
    int r, c;
    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++)
            printf("%.2lf ", arr[r][c]);
        putchar('\n');
    }
}
