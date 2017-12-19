#include <stdio.h>
#include <limits.h>

int count_open_bits(int num);
char *itobs(int n, char *ps);
void show_bstr(const char *str);

int main(void) {
    int num;
    char bin_str[CHAR_BIT * sizeof(int) + 1];

    puts("Please enter a integer number:");
    scanf("%d", &num);
    
    itobs(num, bin_str);
    printf("%s has %d open bits.\n",
            bin_str, count_open_bits(num));

    return 0;
}

int count_open_bits(int num) {
    int count = 0;

    while (num) {
        if ((num & 01) == 1)
            count++;
        num >>= 1;
    }

    return count;
}

void show_bstr(const char *str) {
    int i = 0;

    while (str[i]) {
        putchar(str[i]);
        if (++i % 4 == 0 && str[i])
            putchar(' ');
    }
}

char *itobs(int n, char *ps) {
    int i;
    const static int size = CHAR_BIT * sizeof(int);
    
    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';
    
    return ps;
}
