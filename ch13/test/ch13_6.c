#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 40

char *s_gets(char *st, int n);

int main(void) {
    FILE *in, *out;
    int ch;
    char fin[LEN];
    char fout[LEN];
    int count = 0;

    printf("Please enter input file: ");
    s_gets(fin, LEN);
    if ((in = fopen(fin, "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", fin);
        exit(EXIT_FAILURE);
    }
    
    strncpy(fout, fin, LEN - 5);
    fout[LEN - 5] = '\0';
    strcat(fout, ".red");
    if ((out = fopen(fout, "w")) == NULL) {
        fprintf(stderr, "Can't open %s\n", fout);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);

    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}
