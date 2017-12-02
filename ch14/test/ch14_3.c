#include <stdio.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char *s_gets(char *st, int n);
void order_by_title(struct book *pbooks[], int count);
void order_by_price(struct book *pbooks[], int count);
void show_books(struct book *pbooks[], int count);

int main(void) {
    struct book library[MAXBKS];
    struct book *pbooks[MAXBKS];
    int count = 0;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL &&
            library[count].title[0] != '\0') {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count].value);
        while (getchar() != '\n')
            continue;
        pbooks[count] = &library[count];
        count++;
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }

    if (count > 0) {
        printf("Here is the list of your books:\n");
        show_books(pbooks, count);
        printf("Here is the list of books order by titile:\n");
        order_by_title(pbooks, count);
        show_books(pbooks, count);
        printf("Here is the list of books order by price:\n");
        order_by_price(pbooks, count);
        show_books(pbooks, count);
    } else
        printf("No books? Too bad.\n");

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

void show_books(struct book *pbooks[], int count) {
    int index;

    for (index = 0; index < count; index++)
        printf("%s by %s: $%.2f\n", pbooks[index]->title,
                pbooks[index]->author, pbooks[index]->value);
}

void order_by_title(struct book *pbooks[], int count) {
    int i, j;
    struct book *temp;

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (strcmp(pbooks[i]->title, pbooks[j]->title) > 0) {
                temp = pbooks[i];
                pbooks[i] = pbooks[j];
                pbooks[j] = temp;
            }
        }
    }
}

void order_by_price(struct book *pbooks[], int count) {
    int i, j;
    struct book *temp;

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (pbooks[i]->value > pbooks[j]->value) {
                temp = pbooks[i];
                pbooks[i] = pbooks[j];
                pbooks[j] = temp;
            }
        }
    }
}
