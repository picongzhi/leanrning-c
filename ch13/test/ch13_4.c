#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i;
    FILE *fp;
    char ch;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s file ...\n", argv[0]);
        exit(-1);
    }

    for (i = 1; i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            fprintf(stderr, "Can't open %s\n", argv[i]);
            continue;
        }
        
        printf("%s content:\n", argv[i]);
        while ((ch = getc(fp)) != EOF) 
            putc(ch, stdout);
        printf("\n");

        if (fclose(fp) != 0) {
            fprintf(stderr, "Can't close %s\n", argv[i]);
            exit(-2);
        }
    }
    puts("Done.");

    return 0;
}
