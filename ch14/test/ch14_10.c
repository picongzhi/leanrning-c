#include <stdio.h>

#define SIZE 4

typedef void (*func)(void);

void a(void);
void b(void);
void c(void);
void d(void);

char get_choice(void);

int main(void) {
    char choice;
    func pfs[SIZE] = {a, b, c, d};

    while (1) {
        choice = get_choice();
        
        if (choice == 'q')
            break;
        
        switch (choice) {
            case 'a':
                pfs[0]();
                break;
            case 'b':
                pfs[1]();
                break;
            case 'c':
                pfs[2]();
                break;
            case 'd':
                pfs[3]();
                break;
            default:
                puts("Please select from a to d");
                break;
        }
    }
    puts("Bye!");

    return 0;
}

void a(void) {
    puts("This is function A");
}

void b(void) {
    puts("This is function B");
}

void c(void) {
    puts("This is function C");
}

void d(void) {
    puts("This is function D");
}

char get_choice(void) {
    char choice;

    puts("Please select a function:");
    puts("a) a  b) b  c) c");
    puts("d) d q) quit");

    choice = getchar();
    while (getchar() != '\n')
        continue;

    return choice;
}
