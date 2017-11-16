#include <stdio.h>
#include <ctype.h>

int alpha_location(char ch);

int main(void) {
    char ch;

    printf("Please enter a character until EOF: ");
    while ((ch = getchar()) != EOF) {
        printf("Location of %c is %d.\n",
                ch, alpha_location(ch));
        while (getchar() != '\n')
            continue;
        printf("Please enter a character until EOF: ");
    }

    return 0;
}

int alpha_location(char ch) {
    if (!isalpha(ch))
        return -1;
    if (islower(ch))
        return ch - 'a' + 1;
    else
        return ch - 'A' + 1;
}
