#include <stdio.h>

#define ROWS 6

int main(void) {
    int i, j, k;
    for (i = 0, k = 0; i < ROWS; i++) {
        for (j = 0; j <= i; j++, k++)
            printf("%c", 'A' + k);
        printf("\n");
    }

    return 0;
}
