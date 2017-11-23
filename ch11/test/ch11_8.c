#include <stdio.h>
#include <string.h>

#define SIZE 20

char *string_in(char *str, char *sub);
char *s_gets(char *str, int n);

int main(void) {
    char str[SIZE];
    char sub[SIZE];
    
    puts("Please enter a string:");
    s_gets(str, SIZE);

    while (1) {
        puts("Please enter a sub string (q to quit):");
        s_gets(sub, SIZE);
        if (sub[0] == 'q')
            break;
        if (string_in(str, sub)) 
            printf("%s is in %s\n", sub, str);
        else
            printf("%s is not in %s\n", sub, str);
    }
    puts("Done!");

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

char *string_in(char *str, char *sub) {
    int i, j;
    int stop = strlen(str) - strlen(sub);

    for (i = 0; i <= stop; i++) {
        for (j = 0; j < (int) strlen(sub); j++)
            if (str[j] != sub[j])
                break;
        if (j == (int) strlen(sub))
            return str;
        else
            str++;
    }

    return NULL;
}
