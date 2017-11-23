#include <stdio.h>

#define SIZE 20

char *s_gets(char *str, int n);
void trim(char *str);

int main(void) {
    char str[SIZE];

    while (1) {
        puts("Please enter a string (empty string to quit):");
        s_gets(str, SIZE);
        if (str[0] == '\0')
            break;

        trim(str);
        printf("%s\n", str);
    }
    puts("Done!");

    return 0;
}

void trim(char *str) {
    char *cur = str;
    while (*str != '\0') {
        if (*str == ' ')
            str++;
        else 
            *cur++ = *str++;
    }
    *cur = '\0';
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
