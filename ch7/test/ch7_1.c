#include <stdio.h>

#define STOP '#'

int main(void) {
    char ch;
    int space_cnt, next_line_cnt, other_cnt;
    space_cnt = next_line_cnt = other_cnt = 0;

    printf("Please enter some text ('#' to quit): \n");
    while ((ch = getchar()) != STOP) {
        if (ch == ' ')
            space_cnt++;
        else if (ch == '\n')
            next_line_cnt++;
        else
            other_cnt++;
    }
    printf("space count %d\n next line count %d\n other count %d\n",
            space_cnt, next_line_cnt, other_cnt);

    return 0;
}
