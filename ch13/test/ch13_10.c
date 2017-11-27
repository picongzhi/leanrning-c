#include <stdio.h>
#include <stdlib.h>

#define SLEN 81

char *s_gets(char *st, int n);

int main(void) {
    long pos;
    char fname[SLEN];
    FILE *fp;
    char ch;

    puts("Enetr file name:");
    s_gets(fname, SLEN);
        
    if ((fp = fopen(fname, "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", fname);
        exit(-1);
    }

    puts("Enter a file position (>= 0), and you will get a string");
    puts("from position to next \\n");
    while (scanf("%ld", &pos) == 1 && pos >= 0) {
        fseek(fp, pos, SEEK_SET);
        puts("Contents:");
        while ((ch = getc(fp)) != '\n' && ch != EOF) {
            putc(ch, stdout);
        }
        puts("\nEnter next position:");
    }
    puts("Done.");

    if (fclose(fp)) {
        fprintf(stderr, "Error closing %s", fname);
        exit(-2);
    }

    return 0;
}

char *s_gets(char *st, int n) {
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}
