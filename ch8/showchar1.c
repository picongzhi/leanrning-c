#include <stdio.h>

void display(char ch, int lines, int width);

int main(void) {
    int ch;
    int rows, cols;
    printf("Enter a character and two integers:\n");
    while ((ch = getchar()) != '\n') {
        scanf("%d %d", &rows, &cols);
        display(ch, rows, cols);
        printf("Enter another character and two integers;\n");
        printf("Enter a newline to quit.\n");
    }
    printf("Bye.\n");
}

void display(char ch, int lines, int width) {
    int row, col;

    for (row = 0; row < lines; row++) {
        for (col = 0; col < width; col++)
            putchar(ch);
        putchar('\n');
    }
}
