#include <stdio.h>

void chline(char ch, int line, int row);

int main(void) {
    char ch;
    int row, line;

    printf("Please enter character: ");
    scanf("%c", &ch);
    printf("Please enter row and line: ");
    scanf("%d %d", &row, &line);
    chline(ch, line, row);

    return 0;
}

void chline(char ch, int line, int row) {
    int i, j;

    for (i = 0; i < row; i++) {
        for (j = 0; j < line; j++)
            printf("%c", ch);
        printf("\n");
    }
}
