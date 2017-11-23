#include <stdio.h>

#define SIZE 20

char *get_first_pos(char *str, char ch);
char *s_gets(char *str, int n);

int main(void) {
    char str[SIZE];
    char ch;
    char *pos;

    printf("Please enter a string: ");
    s_gets(str, SIZE);
    printf("Please enter a character: ");
    scanf("%c", &ch);
    puts(str);
    pos = get_first_pos(str, ch);
    if (pos)
        printf("First position of %c in %s is %ld\n", 
                ch, str, pos - str);
    else
        printf("Not found!\n");

    return 0;
}

char *s_gets(char *str, int n) {
    char *ret_val;
    int i = 0;

    ret_val = fgets(str, n, stdin);
    if (ret_val) {
        while (str[i] != '\n' && str[i] != '\0')
            i++;
        if (str[i] == '\n')
            str[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}

char *get_first_pos(char *str, char ch) {
    while (*str != '\0') {
        if (*str == ch)
            return str;
        str++;
    }

    return NULL;
}
