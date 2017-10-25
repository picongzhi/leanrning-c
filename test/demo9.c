#include <stdio.h>

int main() {
    int a = 21;
    int b = 10;
    int c;

    c = a + b;
    printf("Line 1 - c的值是 %d\n", c);
    c = a - b;
    printf("Line 2 - c的值是 %d\n", c);
    c = a * b;
    printf("Line 3 - c的值是 %d\n", c);
    c = a / b;
    printf("Line 4 - c的值是 %d\n", c);
    c = a % b;
    printf("Line 5 - c的值是 %d\n", c);
    c = a++;
    printf("Line 6 - c的值是 %d\n", c);
    c = a--;
    printf("Line 7 - c的值是 %d\n", c);

    return 0;
}
