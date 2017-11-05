#include <stdio.h>

int main(void) {
    char name[20];
    float height;

    printf("Please enter your name and height(cm): ");
    scanf("%s %f", name, &height);
    printf("%s, you are %.2f meter tall\n",
            name, height / 100.0f);

    return 0;
}
