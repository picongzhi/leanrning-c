#include <stdio.h>
#include <limits.h>

void rotate_l(unsigned int *x, int n);
char *itobs(unsigned int n, char *ps);
void show_bstr(const char *str);

int main(void) { 
    unsigned int x, n;
    char bin_str[CHAR_BIT * sizeof(unsigned int) + 1];

    puts("Enter a unsigned int value and a ratete times:");
    scanf("%u %u", &x, &n);
    
    puts("Before rotate:");
    show_bstr(itobs(x, bin_str));
    rotate_l(&x, n);
    puts("\nAfter rotate:");
    show_bstr(itobs(x, bin_str));

    return 0;
}

void show_bstr(const char *str) {
    int i = 0;

    while (str[i]) {
        putchar(str[i]);
        if (++i % 4 == 0 && str[i])
            putchar(' ');
    }
}

char *itobs(unsigned int n, char *ps) {
    int i;
    const static int size = CHAR_BIT * sizeof(unsigned int);
    
    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';

    return ps;
}

void rotate_l(unsigned int *x, int n) {
    int i;
    int length = sizeof(unsigned int) * 8;
    int mask = 1;
    int cur;

    for (i = 0; i < length - 1; i++)
        mask <<= 1;
    
    for (i = 0; i < n; i++) {
        cur = (mask & *x) ? 1 : 0;
        *x <<= 1;
        *x |= cur;
    }
}
