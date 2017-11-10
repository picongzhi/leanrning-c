#include <stdio.h>

int main(void) {
    char ch;
    int change_times = 0;

    printf("Please enter some text ('#' to quit): ");
    while ((ch = getchar()) != '#')
        if (ch == '!' || ch == '.')
            change_times++;
    printf("Change tiems: %d\n", change_times);

    return 0;
}
