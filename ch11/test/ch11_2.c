#include <stdio.h>
#include <ctype.h>

#define SIZE 80

char *getn(char *str, int n);

int main(void) {
    int n;
    char str[SIZE];
    
    puts("Please enter n: ");
    scanf("%d", &n);
    while (getchar() != '\n')
        continue;

    puts("Please enter some characters: ");
    getn(str, n);

    printf("The first %d characters are: %s", n, str);
    printf("\n");

    return 0;
}

char *getn(char *str, int n) {
    int i = 0;
    while (i < n) {
        str[i] = getchar();
        if (isspace(str[i])) 
            break;
        i++;
    }
    str[i] = '\0';

    return str;
}
