#include <stdio.h>

int main() {
    unsigned int a = 60;
    unsigned int b = 13;
    int c = 0;

    c = a & b;
    printf("Line1 - c的值是%d\n", c);

    c = a | b;
    printf("Line2 - c的值是%d\n", c);

    c = a ^ b;
    printf("Line3 - c的值是%d\n", c);

    c = ~a;
    printf("Line4 - c的值是%d\n", c);

    c = a << 2;
    printf("Line5 - c的值是%d\n", c);

    c = a >> 2;
    printf("Line6 - c的值是%d\n", c);
    
    return 0;
}
