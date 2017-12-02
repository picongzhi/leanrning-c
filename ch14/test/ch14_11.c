#include <stdio.h>
#include <math.h>

#define SIZE 100

typedef double (*pf)(double);

void show_arr(const double *, int size);
void init_arr(double *, int size);
void transform(double *, double *, int, double (double));
double add(double);
double sub(double);

int main(void) {
    double source[SIZE];
    double target[SIZE];

    init_arr(source, SIZE);
    
    puts("Original:");
    show_arr(source, SIZE);
    
    puts("Sqrt:");
    transform(source, target, SIZE, sqrt);
    show_arr(target, SIZE);

    puts("log10:");
    transform(source, target, SIZE, log10);
    show_arr(target, SIZE);
    
    puts("Add:");
    transform(source, target, SIZE, add);
    show_arr(target, SIZE);

    puts("Sub:");
    transform(source, target, SIZE, sub);
    show_arr(target, SIZE);

    return 0;
}

double add(double num) {
    return num + 1;
}

double sub(double num) {
    return num - 1;
}

void init_arr(double *num, int size) {
    int i;

    for (i = 0; i < size; i++)
        num[i] = i;
}

void show_arr(const double *num, int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%5.2lf ", num[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
}

void transform(double *source, double *target, int size, double (*func)(double)) {
    int i;

    for (i = 0; i < size; i++)
        target[i] = func(source[i]);
}
