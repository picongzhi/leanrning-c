#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LIM 10
#define SIZE 20

char *s_gets(char *str, int n);
void get_input(char input[LIM][SIZE], char *ptstr[LIM]);
char show_menu(void);
void print(char input[LIM][SIZE]);
void sort_by_ascii_print(char *ptstr[LIM], int n);
void sort_by_len_print(char *ptstr[LIM], int n);
void sort_by_first_word_print(char *ptstr[LIM], int n);
int first_word_length(char *str);
int get_len(char input[LIM][SIZE]);
void print_str(char *ptstr[LIM], int n);

int main(void) {
    char ch;
    char input[LIM][SIZE];
    char *ptstr[LIM];
    int n;

    get_input(input, ptstr);
    n = get_len(input);

    while (1) {
        ch = show_menu();

        switch(ch) {
            case '1':
                print(input);
                break;
            case '2':
                sort_by_ascii_print(ptstr, n);
                break;
            case '3':
                sort_by_len_print(ptstr, n);
                break;
            case '4':
                sort_by_first_word_print(ptstr, n);
                break;
            case '5':
                break;
            default:
                puts("Please enter 1~5");
                break;
        }
        if (ch == '5')
            break;
    }
    puts("Bye!");

    return 0;
}

void print_str(char *ptstr[LIM], int n) {
    int i;

    for (i = 0; i < n; i++)
        printf("%s\n", ptstr[i]);
}

int get_len(char input[LIM][SIZE]) {
    int n = 0;

    while (input[n][0] != '\0')
        n++;

    return n;
}

void print(char input[LIM][SIZE]) {
    int i;
    for (i = 0; i < LIM && input[i][0] != '\0'; i++)
        puts(input[i]);
}

void sort_by_ascii_print(char *ptstr[LIM], int n) {
    int i, j;
    char *temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(ptstr[i], ptstr[j]) > 0) {
               temp = ptstr[i];
               ptstr[i] = ptstr[j];
               ptstr[j] = temp;
            }
        }
    }
    print_str(ptstr, n);
}

void sort_by_len_print(char *ptstr[LIM], int n) {
    int i, j;
    char *temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strlen(ptstr[i]) > strlen(ptstr[j])) {
                temp = ptstr[i];
                ptstr[i] = ptstr[j];
                ptstr[j] = temp;
            }
        }
    }
    print_str(ptstr, n);
}

void sort_by_first_word_print(char *ptstr[LIM], int n) {
    int i, j;
    char *temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (first_word_length(ptstr[i]) > first_word_length(ptstr[j])) {
                temp = ptstr[i];
                ptstr[i] = ptstr[j];
                ptstr[j] = temp;
            }
        }
    }   
    print_str(ptstr, n);
}

int first_word_length(char *str) {
    int len;
    while (isspace(*str))
        str++;
    len = 1;
    while (!isspace(*str)) {
        str++;
        len++;
    }

    return len;
}

char show_menu(void) {
    char ch;
    
    puts("********************");
    puts("1. Print the string");
    puts("2. Sort by ASCII and print");
    puts("3. Sort by length and print");
    puts("4. Sort by first word and print");
    puts("5. Quit");
    puts("********************");
    puts("What's your selection?");
    ch = getchar();
    while (getchar() != '\n')
        continue;

    return ch;
}

void get_input(char input[LIM][SIZE], char *ptstr[LIM]) {
    int i = 0;

    printf("Please enter %d strings or empty to quit\n", LIM);
    while (i < LIM && s_gets(input[i], SIZE) != NULL &&
            input[i][0] != '\0') {
        ptstr[i] = input[i];
        i++;
    }
}

char *s_gets(char *str, int n) {
    char *ret_val;
    int i = 0;

    ret_val = fgets(str, n, stdin);
    if (ret_val) {
        while (str[i] != '\n' && str[i] != '\0')
            i++;
        if (str[i] == '\n')
            str[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    
    return ret_val;
}
