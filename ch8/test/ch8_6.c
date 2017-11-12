#include <stdio.h>
#include <ctype.h>

char get_first(void);

int main(void) {
    char ch;
    printf("Please enter some text, and you will only get the first non-blank space.\n");
    ch = get_first();
    printf("%c\n", ch);

    return 0;
}

char get_first(void) {
    int ch;

    ch = getchar();
    while (isspace(ch))
        ch = getchar();
    while (getchar() != '\n')
        continue;

    return ch;
}
