#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024

char *s_gets(FILE *fp, char *st, int n);

int main(int argc, char *argv[]) {
    FILE *fp1, *fp2;
    char line[MAXLINE];
    int is_eof1, is_eof2;
    is_eof1 = is_eof2 = 0;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
        exit(-1);
    }
    
    if ((fp1 = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(-2);
    }
    if ((fp2 = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        exit(-2);
    }

    while (1) {
        if (is_eof1 && is_eof2)
            break;
        if (!is_eof1) {
            if (s_gets(fp1, line, MAXLINE))
                printf("%s\n", line);
            else
                is_eof1 = 1;
        }
        if (!is_eof2) {
            if (s_gets(fp2, line, MAXLINE))
                printf("%s\n", line);
            else
                is_eof2 = 1;
        }
    }

    if (fclose(fp1) && fclose(fp2))
        fputs("File close failed.\n", stdout);

    return 0;
}

char *s_gets(FILE *fp, char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, fp);
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
