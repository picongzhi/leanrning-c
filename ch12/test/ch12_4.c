#include <stdio.h>

unsigned int count_called(void);

int main(void) {
    int i;

    for (i = 0; i < 100; i++)
        printf("Function called %d times.\n", count_called());

    return 0;
}

unsigned int count_called(void) {
    static int count = 0;
    return ++count;
}
