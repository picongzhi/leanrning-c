#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char search, ch;
    int count;
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s character file\n", argv[0]);
        exit(-1);
    }
    
    search = argv[1][0];
    if (argc == 2) {
        count = 0;
        while ((ch = getchar()) != EOF)
            if (ch == search)
                count++;
        
        printf("You have entered %d %c\n", count, search);
    } else {
        for (i = 2; i < argc; i++) {
            count = 0;
            if ((fp = fopen(argv[2], "r")) == NULL) {
                fprintf(stderr, "Can't open %s\n", argv[2]);
                continue;
            }
            
            while ((ch = getc(fp)) != EOF)
                if (ch == search)
                    count++;
            
            if (fclose(fp)) 
                fprintf(stderr, "File %s close failed.\n", argv[i]);
            
            printf("File %s has %d %c\n", argv[i], count, search);
        }
    }
    
    return 0;
}
