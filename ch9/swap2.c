#include <stdio.h>

void intercharge(int u, int v);

int main(void) {
    int x = 5, y = 10;

    printf("Originally x = %d and y = %d.\n", x, y);
    intercharge(x, y);
    printf("Now x = %d and y = %d.\n", x, y);

    return 0;
}

void intercharge(int u, int v) {
    int temp;

    printf("Originally u = %d and v = %d.\n", u, v);
    temp = u;
    u = v;
    v = temp;
    printf("Now u = %d and v = %d.\n", u, v);
}
