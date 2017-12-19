#include <stdio.h>
#include <ctype.h>

int str2bin(char *str);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s str\n", argv[0]);
        return 1;
    }
    printf("%s is %d\n", argv[1], str2bin(argv[1]));

    return 0;
}

int str2bin(char *str) {
    int res = 0;

    while (*str) {
        if (isdigit(*str) && (*str == '0' || *str == '1'))
            res = res * 2 + (*str - '0');
        else
            return -1;
        str++;
    }

    return res;
}
