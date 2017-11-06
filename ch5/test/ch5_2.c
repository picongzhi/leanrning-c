#include <stdio.h>

int main(void) {
    int num;
    int i;
    printf("Please enter an integer: ");
    scanf("%d", &num);
    i = num;
    while (i <= num + 10) {
        printf("%d ", i);
        i++;
    }
    printf("\n");

    return 0;
}
