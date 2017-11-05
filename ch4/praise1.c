#include <stdio.h>

#define PRAISE "You are an extraordinary being."

int main(void) {
    char name[10];

    printf("What's your name? ");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISE);

    return 0;
}
