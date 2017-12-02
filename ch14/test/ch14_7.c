#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

char *s_gets(char *st, int n);

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    bool is_active;
};

int main(void) {
    struct book library[MAXBKS];
    int count = 0;
    int index, filecount;
    FILE *pbooks;
    int size = sizeof(struct book);
    char oper;
    int num;

    if ((pbooks = fopen("book.dat", "r+b")) == NULL) {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }

    while (count < MAXBKS && fread(&library[count], size, 
                1, pbooks) == 1) {
        if (count == 0)
            puts("Current contents of book.dat:");
        
        if (library[count].is_active)
            printf("%s by %s: $%.2f\n", library[count].title,
                    library[count].author, library[count].value);
            count++;
    }
    filecount = count;
    if (count == MAXBKS) {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }

    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL &&
            library[count].title[0] != '\0') {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        
        puts("Now enter the value.");
        scanf("%f", &library[count].value);
        while (getchar() != '\n')
            continue;
        
        library[count++].is_active = true;
         
        if (count < MAXBKS)
            puts("Enter the next title.");
    }
    fclose(pbooks);
    
    if (count > 0) {
        while (true) {
            puts("Here is the list of your books:");
            for (index = 0; index < count; index++) {
                if (library[index].is_active)
                    printf("%d: %s by %s: $%.2f\n", index, library[index].title, 
                            library[index].author, library[index].value);
            }
            
            puts("Enter your operation:");
            puts("c. change  d. delete  q. quit");
            oper = getchar();
            while (getchar() != '\n')
                continue;
            
            if (oper == 'q')
                break;
            else if (oper == 'c') {
                puts("Enter the index you want to change:");
                scanf("%d", &num);
                while (getchar() != '\n')
                    continue;

                if (num >= 0 && num < count) {
                    puts("Please enter the title:");
                    s_gets(library[num].title, MAXTITL);
                    
                    puts("Now enter the author:");
                    s_gets(library[num].author, MAXAUTL);
                    
                    puts("Now enter the value:");
                    scanf("%f", &library[num].value);
                    while (getchar() != '\n')
                        continue;
                } else {
                    puts("Invalid index.");
                    continue;
                }
            } else if (oper == 'd') {
                puts("Enter the index you want to change:");
                scanf("%d", &num);
                while (getchar() != '\n')
                    continue;

                if (num >= 0 && num < count)
                    library[num].is_active = false;
            } else {
                puts("Invalid operation, enter again.");
                continue;
            }
        }
        
        if ((pbooks = fopen("book.dat", "wb")) == NULL) {
            fprintf(stderr, "Can't write book.dat file.\n");
            exit(3);
        }

        for (index = 0; index < count; index++) {
            if (library[index].is_active)
                fwrite(&library[index], size, 1, pbooks);
        }

        fclose(pbooks);
    } else 
        puts("No books? Too bad.\n");
    
    puts("Bye.\n");

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
