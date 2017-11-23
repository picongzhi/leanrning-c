#include <stdio.h>
#include <ctype.h>

int myatoi(char *str);

int main(int argc, char *argv[]) {
    int n;

    if (argc != 2)
        puts("Usage: ./a.out 123");
    else {
        n = myatoi(argv[1]);
        if (n)
            printf("%d\n", n);
        else
            puts("Not a valid integer number!");
    }

    return 0;
}

int myatoi(char *str) {
    int res = 0;
    
    while (*str) {
        if (!isdigit(*str))
            return 0;
        res = res * 10 + (*str - '0');
        str++;
    }

    return res;
}
