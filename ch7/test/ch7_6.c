#include <stdio.h>

int main(void) {
    char prev, cur;
    int count = 0;
    prev = '#';
    printf("Please enter some text ('#' to quit): ");
    while ((cur = getchar()) != '#') {
        if (prev == 'e' && cur == 'i')
            count++;
        prev = cur;
    }
    printf("'ei' occured %d times.\n", count);

    return 0;
}
