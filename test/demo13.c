#include <stdio.h>

int main() {
    int a = 21;
    int c;

    c = a;
    printf("Line1 - = 运算符实例, c的值 = %d\n", c);

    c += a;
    printf("Line2 - += 运算符实例, c的值 = %d\n", c);

    c -= a;
    printf("Line3 - -= 运算符实例, c的值 = %d\n", c);

    c *= a;
    printf("Line4 - *= 运算符实例, c的值 = %d\n", c);

    c /= a;
    printf("Line5 - /= 运算符实例, c的值 = %d\n", c);

    c = 200;
    c %= a;
    printf("Line6 - %= 运算符实例, c的值 = %d\n", c);

    c <<= 2;
    printf("Line7 - <<= 运算符实例, c的值 = %d\n", c);

    c >>= 2;
    printf("Line8 - >>= 运算符实例, c的值 = %d\n", c);

    c &= 2;
    printf("Line9 - &= 运算符实例, c的值 = %d\n", c);

    c ^= 2;
    printf("Line10 - ^= 运算符实例, c的值 = %d\n", c);

    c |= 2;
    printf("Line11 - |= 运算符实例, c的值 = %d\n", c);

    return 0;
}
