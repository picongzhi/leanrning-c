#include <stdio.h>

#define LINE_LIMIT 8
#define STOP '#'

int main(void) {
    char ch;
    int i = 0;
    printf("Please enter some text ('#' to quit):\n");
    while ((ch = getchar()) != STOP) {
        if (++i % LINE_LIMIT == 0)
            printf("%c is %d\n", ch, ch);
        else
            printf("%c is %d ", ch, ch);
    }
    printf("Done\n");

    return 0;
}
