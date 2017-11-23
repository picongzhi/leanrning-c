#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 20

char *get_word(char *str, int n);

int main(int argc, char *argv[]) {
    char word[SIZE];
    int n;
    
    if (argc < 2 || (n = atoi(argv[1])) < 1)
        printf("Usage: ./a.out positive-number.\n");
    else {
        get_word(word, n);
        puts(word);
    }
    
    return 0;
}

char *get_word(char *str, int n) {
    int i;
    char ch;
    
    ch = getchar();
    while (isspace(ch))
        ch = getchar();
    for (i = 0; i < n && !isspace(ch); i++, ch = getchar())
        str[i] = ch;
    str[i] = '\0';
    if (ch != '\n')
        while (getchar() != '\n')
            continue;
    
    return str;
}
