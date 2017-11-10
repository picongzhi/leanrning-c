#include <stdio.h>

#define BASE 1000
#define OVERTIME_RATE 1.5
#define HOUR_BREAK 40

#define RATE_BREAK1 300
#define RATE_BREAK2 450

#define RATE1 0.15
#define RATE2 0.2
#define RATE3 0.25

int main(void) {
    int hours;
    float salary_without_sax;
    float salary_with_sax;
    
    printf("Please enter hours of a week: ");
    scanf("%d", &hours);
    if (hours <= HOUR_BREAK) {
        salary_without_sax = BASE * hours;
    } else {
        salary_without_sax = BASE * HOUR_BREAK + 
            (hours - HOUR_BREAK) * BASE * OVERTIME_RATE;
    }
    if (salary_without_sax < RATE_BREAK1)
        salary_with_sax = (1 - RATE1) * salary_without_sax;
    else if (salary_without_sax < RATE_BREAK2)
        salary_with_sax = (1 - RATE1) * RATE_BREAK1 +
            (1 - RATE2) * (salary_without_sax - RATE_BREAK1);
    else
        salary_with_sax = (1 - RATE1) * RATE_BREAK1 +
            (1 - RATE2) * (RATE_BREAK2 - RATE_BREAK2) +
            (1 - RATE3) * (salary_without_sax - RATE_BREAK2);
    printf("Total salary is %.2f\n", salary_without_sax);
    printf("Tax is %.2f\n", salary_without_sax - salary_with_sax);
    printf("Salary after tax is %.2f\n", salary_with_sax);

    return 0;

}
