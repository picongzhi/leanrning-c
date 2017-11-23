#include <stdio.h>

#define SIZE 20

char *s_gets(char *str, int n);
int is_within(char ch, char *str);

int main(void) {
    char str[SIZE];
    char ch;

    while (1) {
        puts("Please enter a string (q to quit):");
        s_gets(str, SIZE);
        if (str[0] == 'q')
            break;
        
        puts("Please enter a character:");
        scanf("%c", &ch);
        while (getchar() != '\n')
            continue;
        
        if (is_within(ch, str))
            printf("%c is in %s\n", ch, str);
        else
            printf("Not found!\n");
    }
    printf("Done!\n");

    return 0;
}

int is_within(char ch, char *str) {
    while (*str) {
        if (ch == *str)
            return 1;
        str++;
    }

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
