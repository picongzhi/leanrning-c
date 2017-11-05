#include <stdio.h>

int main(void) {
    float cup;
    printf("Enter cups: ");
    scanf("%f", &cup);

    printf("%f cup(s)\n", cup);
    printf("%f pint(s)\n", cup / 2.0f);
    printf("%f ounce(s)\n", cup * 8.0f);
    printf("%f soup ladle(s)\n", cup * 8.0f * 2.0f);
    printf("%f tea ladle(s)\n", cup * 8.0f * 2.0f * 3.0f);

    return 0;
}
