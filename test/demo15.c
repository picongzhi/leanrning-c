#include <stdio.h>

int main() {
    int a = 20;
    int b = 10;
    int c = 15;
    int d = 5;
    int e;

    e = (a + b) * c / d;
    printf("(a + b) * c / d 的值是 %d\n", e);

    e = ((a + b) * c) / d;
    printf("((a + b) * c / d) 的值是 %d\n", e);

    e = (a + b) * (c / d);
    printf("(a + b) * (c / d) 的值是 %d\n", e);

    e = a + (b * c) / d;
    printf("a + (b * c) / d 的值是 %d\n", e);

    return 0;
}
