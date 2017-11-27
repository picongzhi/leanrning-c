#include <stdio.h>
#include <stdlib.h>

#define SLEN 81
#define BUFSIZE 4096

int main(int argc, char *argv[]) {
    FILE *source, *dest;
    char *source_file;
    char *dest_file;
    size_t bytes;
    char buf[BUFSIZE];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s source dest\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    source_file = argv[1];
    dest_file = argv[2];

    if ((source = fopen(source_file, "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", source_file);
        exit(-1);
    }
    if ((dest = fopen(dest_file, "wb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", dest_file);
        exit(-2);
    }

    while ((bytes = fread(buf, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(buf, sizeof(char), bytes, dest);
    puts("Done copying.");

    fclose(source);
    fclose(dest);

    return 0;
}
