#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SLEN 81

char *s_gets(char *st, int n);

int main(void) {
    char fname[SLEN];
    int ch;
    FILE *fp;

    puts("Please enter file name:");
    s_gets(fname, SLEN);

    if ((fp = fopen(fname, "r+")) == NULL) {
        fprintf(stderr, "Can't open %s\n", fname);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF) {
        fseek(fp, -1, SEEK_CUR);
        putc(toupper(ch), fp);
    }
    puts("Done.");

    if (fclose(fp) != 0) {
        fprintf(stderr, "Can't close %s\n", fname);
        exit(EXIT_FAILURE);
    }

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
