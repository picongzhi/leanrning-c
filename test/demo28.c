#include <stdio.h>
#include <string.h>

struct Books {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

int main() {
    struct Books book1;
    struct Books book2;

    strcpy(book1.title, "C Programming");
    strcpy(book1.author, "Nuha Ali");
    strcpy(book1.subject, "C Programming Tutorial");
    book1.book_id = 6495407;

    strcpy(book2.title, "Telecom Billing");
    strcpy(book2.author, "Zara Ali");
    strcpy(book2.subject, "Telecom Billing Tutorial");
    book2.book_id = 6495700;

    printf("Book 1 title: %s\n", book1.title);
    printf("Book 1 author: %s\n", book1.author);
    printf("Book 1 subject: %s\n", book1.subject);
    printf("Book 1 book_id: %d\n", book1.book_id);
    
    printf("Book 2 title: %s\n", book2.title);
    printf("Book 2 author: %s\n", book2.author);
    printf("Book 2 subject: %s\n", book2.subject);
    printf("Book 2 book_id: %d\n", book2.book_id);

    return 0;
}
