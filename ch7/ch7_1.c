#include <stdio.h>

int main(void) {
    char chars[26];
    char ch = 'a';
    int i;
    for (i = 0; i < 26; i++) {
        chars[i] = ch + i;
    }
    for (i = 0; i < 26; i++) {
        printf("%c ", chars[i]);
    }
    printf("\n");

    return 0;
}
