#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main(void) {
    FILE *fp;
    char words[MAX];
    int line = 0;

    if ((fp = fopen("wordy", "r")) == NULL) {
        fprintf(stderr, "Can't open \"wordy\" file.\n");
        if ((fp = fopen("wordy", "w")) == NULL) {
            fprintf(stderr, "Can't create \"wordy\" file.\n");
            exit(-1);
        }
    }
    while ((fscanf(fp, "%s", words)) == 1)
        line++;
    line++;
    printf("%d\n", line);

    if ((fp = fopen("wordy", "a+")) == NULL) {
        fprintf(stderr, "Can't open \"wordy\" file.\n");
        exit(-1);
    }

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%d.%s\n", line++, words);

    puts("File contents:");
    rewind(fp);
    while (fscanf(fp, "%s", words) == 1)
        puts(words);
    puts("Done!");
    if (fclose(fp))
        fprintf(stderr, "Error closing file\n");

    return 0;
}
