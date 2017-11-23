#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

void to_upper(char *str);
void to_lower(char *str);
void print_str(char *str);

int main(int argc, char *argv[]) {
    char ch;
    char str[SIZE];
    int i = 0;

    puts("Please enter some text (EOF to stop): ");
    while ((ch = getchar()) != EOF) {
        str[i++] = ch;
    }
    str[i] = '\0';

    if (argc == 1)
        print_str(str);
    else if (argc == 2) {
        if (!strcmp("-p", argv[1]))
            print_str(str);
        else if (!strcmp("-u", argv[1])) {    
            to_upper(str);
            print_str(str);
        } else if (!strcmp("-l", argv[1])) {
            to_lower(str);
            print_str(str);
        } else
            puts("Invalid parameter!");
    } else 
        puts("Invalid arguments!");

    return 0;
}

void print_str(char *str) {
    printf("%s", str);
}

void to_upper(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

void to_lower(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}
