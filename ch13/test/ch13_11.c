#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

char *get_line(FILE *fp, char *line, int n);

int main(int argc, char *argv[]) {
    char *str;
    char *fname;
    char line[MAX];
    FILE *fp;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s string filename\n", argv[0]);
        exit(-1);
    }
    str = argv[1];
    fname = argv[2];

    if ((fp = fopen(fname, "r")) == NULL) {
        fprintf(stderr, "Can't open %s", fname);
        exit(-2);
    }

    while (get_line(fp, line, MAX))
        if (strstr(line, str))
            printf("%s\n", line);

    if (fclose(fp)) {
        fprintf(stderr, "Error closing %s", fname);
        exit(-3);
    }
    
    return 0;
}

char *get_line(FILE *fp, char *line, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(line, n, fp);
    if (ret_val) {
        find = strchr(line, '\n');
        if (find)
            *find = '\0';
    }

    return ret_val;
}
