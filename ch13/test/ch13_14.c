#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 20
#define COLS 30

void print_num(int num[ROWS][COLS]);
char to_char(int n);
void print_char(char *str[], int rows); 

int main(int argc, char *argv[]) {
    FILE *fp;
    int num[ROWS][COLS];
    char *chs[COLS + 1];
    int row, col;
    char ch;
    float avg;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        exit(-1);
    }
    
    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(-2);
    }
    
    row = col = 0;
    while ((ch = getc(fp)) != EOF) {
        if (ch == ' ')
            continue;
        else if (ch == '\n') {
            row++;
            col = 0;
        } else {
            num[row][col] = ch - '0';
            col++;
        }
    }

    for (row = 0; row < ROWS; row++) {
        chs[row] = (char *) malloc(sizeof(char) * (COLS + 1));
        for (col = 0; col < COLS; col++) {
            if (row > 0 && row < ROWS - 1 && col > 0 && col < COLS - 1) {
                if ((abs(num[row][col] - num[row - 1][col]) > 1) &&
                        (abs(num[row][col] - num[row + 1][col]) > 1) &&
                        (abs(num[row][col] - num[row][col - 1]) > 1) &&
                        (abs(num[row][col] - num[row][col + 1]) > 1)) { 
                    avg = (num[row][col - 1] + 
                                num[row][col + 1] + num[row - 1][col] +
                                num[row + 1][col]) / 4.0;
                    if ((avg - (int) avg) >= 0.5)
                        chs[row][col] = to_char((int) avg + 1);
                    else
                        chs[row][col] = to_char((int) avg);
                } else
                    chs[row][col] = to_char(num[row][col]);
            } else 
                chs[row][col] = to_char(num[row][col]);
        }
        chs[row][col + 1] = '\0';
    }

    print_char(chs, ROWS);
    
    for (row = 0; row < ROWS; row++) 
        free(chs[row]);

    if (fclose(fp)) {
        fprintf(stderr, "Error closing %s\n", argv[1]);
        exit(-3);
    }

    return 0;
}

void print_char(char *str[], int rows) {
    int row;

    for (row = 0; row < rows; row++)
        printf("%s\n", str[row]);
}

char to_char(int n) {
    char ch;
    switch (n) {
        case 0:
            ch = ' ';
            break;
        case 1:
            ch = '.';
            break;
        case 2:
            ch = '\'';
            break;
        case 3:
            ch = ':';
            break;
        case 4:
            ch = '~';
            break;
        case 5:
            ch = '*';
            break;
        case 6:
            ch = '=';
            break;
        case 7:
            ch = '|';
            break;
        case 8:
            ch = '%';
            break;
        case 9:
            ch = '#';
            break;
    }

    return ch;
}

void print_num(int num[ROWS][COLS]) {
    int r, c;

    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++)
            printf("%d ", num[r][c]);
        printf("\n");
    }
}
