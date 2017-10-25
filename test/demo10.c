#include <stdio.h>

int main() {
    int a = 21;
    int b = 10;
    int c;

    if (a == b) {
        printf("Line1 - a 等于 b\n");
    } else {
        printf("Line1 - a 不等于 b\n");
    }

    if (a < b) {
        printf("Line2 - a 小于 b\n");
    } else {
        printf("Line2 - a 不小于 b\n");
    }

    if (a > b) {
        printf("Line3 - a 大于 b\n");
    } else {
        printf("Line3 - a 不大于 b\n");
    }

    a = 5;
    b = 20;
    if (a <= b) {
        printf("Line4 - a 小于或等于b\n");
    }

    if (b >= a) {
        printf("Line5 - b 大于或等于a\n");
    }

    return 0;
}
