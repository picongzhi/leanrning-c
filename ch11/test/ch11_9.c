#include <stdio.h>
#include <string.h>

#define SIZE 20

char *str_reverse(char *str);
char *s_gets(char *str, int n);

int main(void) {
    char str[SIZE];
    
    while (1) {
        puts("Please enter a string (q to quit):");
        s_gets(str, SIZE);
        if (str[0] == 'q')
            break;
        
        str_reverse(str);
        puts("After reverse:");
        printf("%s\n", str);
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

char *str_reverse(char *str) {
    char temp;
    int i;
    int len = strlen(str);

    for (i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    return str;
}
