#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLEN 81

char *s_gets(char *st, int n);

int main(void) {
    int ch;
    FILE *fp;
    char fname[SLEN];
    unsigned long count = 0;

    printf("Please enter file name: ");
    s_gets(fname, SLEN);
    if ((fp = fopen(fname, "r")) == NULL) {
        printf("Can't open %s\n", fname);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF) {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", fname, count);

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
