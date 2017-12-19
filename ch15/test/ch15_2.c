#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int str2int(char *str);
char *itobs(int n, char *ps);
void show_bstr(const char *str);

int main(int argc, char *argv[]) {
    int num1, num2;
    char bin_str[CHAR_BIT * sizeof(int) + 1];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s binary_str1 binary_str2\n",
                argv[0]);
        exit(1);
    }

    num1 = str2int(argv[1]);
    num2 = str2int(argv[2]);
    
    if (num1 == -1 || num2 == -1) {
        fputs("Please enter binary string.", stderr);
        exit(2);
    } 

    itobs(~num1, bin_str);
    printf("~%s = ", argv[1]);
    show_bstr(bin_str);
    
    itobs(~num2, bin_str);
    printf("~%s = ", argv[2]);
    show_bstr(bin_str);

    itobs(num1 & num2, bin_str);
    printf("%s & %s = ", argv[1], argv[2]);
    show_bstr(bin_str);

    itobs(num1 | num2, bin_str);
    printf("%s | %s = ", argv[1], argv[2]);
    show_bstr(bin_str);

    itobs(num1 ^ num2, bin_str);
    printf("%s ^ %s = ", argv[1], argv[2]);
    show_bstr(bin_str);

    return 0;
}

void show_bstr(const char *str) {
    int i = 0;

    while (str[i]) {
        putchar(str[i]);
        if (++i % 4 == 0 && str[i])
            putchar(' ');
    }
    printf("\n");
}

char *itobs(int n, char *ps) {
    int i;
    const static int size = CHAR_BIT * sizeof(int);
    
    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';

    return ps;
}

int str2int(char *str) {
    int num, cur;
    num = 0;

    while (*str) {
        if (*str != '0' && *str != '1')
            return -1;
        cur = (*str == '1') ? 1 : 0;
        num = num * 2 + cur;
        str++;
    }

    return num;
}
