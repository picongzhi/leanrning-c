#include <stdio.h>

int main() {
    int a = 4;
    short b;
    double c;
    int* ptr;

    printf("Line1 - 变量 a 的大小 = %lu\n", sizeof(a));
    printf("Line2 - 变量 b 的大小 = %lu\n", sizeof(b));
    printf("Line3 - 变量 c 的大小 = %lu\n", sizeof(c));

    ptr = &a;
    printf("a 的值是 %d\n", a);
    printf("*ptr 是 %d\n", *ptr);

    a = 10;
    b = (a == 1) ? 20 : 30;
    printf("b 的值是 %d\n", b);

    b = (a == 10) ? 20 : 30;
    printf("b 的值是 %d\n", b);

    return 0;
}
