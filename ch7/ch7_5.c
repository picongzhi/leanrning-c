#include <stdio.h>

int main(void) {
    int i, j;
    char ch;
    printf("Please enter upper case letter: ");
    scanf("%c", &ch);

    if (ch < 'A' || ch > 'Z') {
        printf("Invalid input!\n");
        return 1;
    }

    for (i = 0; i <= ch - 'A'; i++) {
        for (j = 0; j < ch - 'A' - i; j++) 
            printf(" ");
        for (j = 0; j <= i; j++)
            printf("%c", 'A' + j);
        for (j = i - 1; j >= 0; j--)
            printf("%c", 'A' + j);
        printf("\n");
    }

    return 0;
}
