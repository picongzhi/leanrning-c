#include <stdio.h>

int main() {
    int a = 5;
    int b = 20;
    int c;

    if (a && b) {
        printf("Line1 - 条件为真\n");
    }
    if (a || b) {
        printf("Line2 - 条件为真\n");
    }
    a = 0;
    b = 10;
    if (a && b) {
        printf("Line3 - 条件为真\n");
    } else {
        printf("Line3 - 条件不为真\n");
    }
    if (!(a && b)) {
        printf("Line4 - 条件为真\n");
    }

    return 0;
}
