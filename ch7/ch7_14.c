#include <stdio.h>

#define SIZE 8

int main(void) {
    int i;
    double arr1[SIZE];
    double arr2[SIZE];
    
    printf("Please enter %d double number: ", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%lf", &arr1[i]);
        if (i == 0)
            arr2[i] = arr1[i];
        else
            arr2[i] = arr1[i] + arr2[i - 1];
    }
    
    for (i = 0; i < SIZE; i++)
        printf("%8.2lf ", arr1[i]);
    printf("\n");
    for (i = 0; i < SIZE; i++)
        printf("%8.2lf ", arr2[i]);
    printf("\n");

    return 0;
}
