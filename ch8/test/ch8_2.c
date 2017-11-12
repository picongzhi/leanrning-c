#include <stdio.h>

int main(void) {
    char ch;
    int i = 0;

    while ((ch = getchar()) != EOF) {
        printf("%c<==>%d ", ch, ch);
        if (i != 0 && i % 10 == 0)
            printf("\n");
    }

    return 0;
}
