#include <stdio.h>

int main(void) {
    char ch;
    int change_times = 0;

    printf("Please enter some text ('#' to quit): ");
    while ((ch = getchar()) != '#') {
        switch (ch) {
            case '!':
            case '.':
                change_times++;
                break;
            default:
                break;
        }
    }
    printf("Change times: %d\n", change_times);

    return 0;
}
