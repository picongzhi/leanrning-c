#include <stdio.h>

int main(void) {
    const int SIZE = 6;
    int i, j;
    char ch = 'F';

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j <= i; j++)
            printf("%c", ch - j);
        printf("\n");
    }

    return 0;
}
