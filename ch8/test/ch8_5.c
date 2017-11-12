#include <stdio.h>

int main(void) {
    int guess = 50;
    int max = 100;
    int min = 1;
    char ch;

    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with a y if my guess is right and with");
    printf("\n a s if my guess is small and with a b if my guess");
    printf("\n is big.\n");
    
    while (1) {
        printf("Uh...is your number %d?\n", guess);
        ch = getchar();
        if (ch == 'y') {
            printf("I knew I could do it!\n");
            break;
        } else if (ch == 's') {
            min = guess;
            guess = (guess + max) / 2;
        } else if (ch == 'b') {
            max = guess;
            guess = (guess + min) / 2;
        } else {
            printf("Invalid input!\n");
        }
        while (getchar() != '\n')
            continue;
    }

    return 0;
}
