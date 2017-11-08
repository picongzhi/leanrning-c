#include <stdio.h>

#define YEAR_RATE 0.08

int main(void) {
    double total = 100.0;
    int year = 0;
    while (total > 10) {
        total = total * (1 + YEAR_RATE) - 10;
        year++;
    }
    printf("After %d years, he will take all money.\n", year);

    return 0;
}
