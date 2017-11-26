#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void print_num(int *num, int n);
void sort(int *num, int n);

int main(void) {
    int i;
    int rand_num[SIZE];
    
    srand((unsigned int) time(0));
    for (i = 0; i < SIZE; i++)
        rand_num[i] = rand() % 10 + 1;
    sort(rand_num, SIZE);
    print_num(rand_num, SIZE);

    return 0;
}

void sort(int *num, int n) {
    int i, j;
    int temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (num[i] < num[j]) {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
}

void print_num(int *num, int n) {
    int i;

    for (i = 1; i <= n; i++) {
        printf("%3d ", num[i - 1]);
        if (i % 10 == 0)
            printf("\n");
    }
}
