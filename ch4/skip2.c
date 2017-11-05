#include <stdio.h>

int main(void) {
    int n;

    printf("Please enter therr integers:\n");
    scanf("%*d %*d %d", &n);
    printf("The last integer was %d\n", n);

    return 0;
}
