#include <stdio.h>

#define SIZE 20

char *mystrncpy(char *s1, const char *str2, int n);
char *s_gets(char *str, int n);

int main(void) {
    char s1[SIZE];
    char s2[SIZE];
    int n;

    while (1) {
        puts("Please enter a string (q to stop):");
        s_gets(s2, SIZE);
        if (s2[0] == 'q')
            break;
        
        puts("Please enter n:");
        scanf("%d", &n);
        while (getchar() != '\n')
            continue;
        
        mystrncpy(s1, s2, n);
        puts("After copying: ");
        printf("%s\n", s1);
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

char *mystrncpy(char *s1, const char *s2, int n) {
    int i;
    for (i = 0; i < n && s2[i] != '\0'; i++)
        s1[i] = s2[i];
    if (i == n)
        s1[i] = '\0';
    
    return s1;
}
