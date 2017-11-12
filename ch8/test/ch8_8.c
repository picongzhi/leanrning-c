#include <stdio.h>

char get_operation(void);
float get_number(void);
void do_add(float a, float b);
void do_substract(float a, float b);
void do_multiply(float a, float b);
void do_divide(float a, float b);

int main(void) {
    char operation;
    float first_number, second_number;
    
    while (1) {
        operation = get_operation();
        if (operation == 'q')
            break;
        printf("Enter first number: ");
        first_number = get_number();
        printf("Enter second number: ");
        second_number = get_number();
        switch (operation) {
            case 'a':
                do_add(first_number, second_number);
                break;
            case 's':
                do_substract(first_number, second_number);
                break;
            case 'm':
                do_multiply(first_number, second_number);
                break;
            case 'd':
                do_divide(first_number, second_number);
                break;
            default:
                break;
        }
    }
    printf("Bye.\n");

    return 0;
}

void do_add(float a, float b) {
    printf("%.1f + %.1f = %.1f\n", a, b, a + b);
}

void do_substract(float a, float b) {
    printf("%.1f + %.1f = %.1f\n", a, b, a - b);
}

void do_multiply(float a, float b) {
    printf("%.1f + %.1f = %.1f\n", a, b, a * b);
}

void do_divide(float a, float b) {
    while (b == 0) {
        printf("Enter a number other than 0: ");
        b = get_number();
    }
    printf("%.1f + %.1f = %.1f\n", a, b, a / b);
}

float get_number(void) {
    float num;
    char ch;

    while (scanf("%f", &num) != 1) {
        while ((ch = getchar()) != '\n')
            printf("%c", ch);
        printf(" is not an number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
    }

    while (getchar() != '\n')
        continue;

    return num;
}

char get_operation(void) {
    char operation;

    printf("Enter the operation of your choice:\n");
    printf("a. add         s. substract\n");
    printf("m. multiply    d. divide\n");
    printf("q. quit\n");
    operation = getchar();
    
    while (getchar() != '\n')
        continue;

    return operation;
}
