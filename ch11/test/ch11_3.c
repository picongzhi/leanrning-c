#include <stdio.h>
#include <ctype.h>

#define SIZE 20

char *get_word(char *str);

int main(void) {
    char word[SIZE];

    printf("Please enter some text: ");
    get_word(word);
    puts(word);

    return 0;
}

char *get_word(char *str) {
    char ch;
    int i;

    ch = getchar();
    while (isspace(ch))
        ch = getchar();
    for (i = 0; !isspace(ch); i++, ch = getchar())
        str[i] = ch;
    str[i] = '\0';
    while (getchar() != '\n')
        continue;

    return str;
}
