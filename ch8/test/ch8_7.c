#include <stdio.h>

#define OVERTIME_RATE 1.5
#define HOUR_BREAK 40

#define RATE_BREAK1 300
#define RATE_BREAK2 450

#define RATE1 0.15
#define RATE2 0.2
#define RATE3 0.25

char get_select(void);

int main(void) {
    int hours;
    char select;
    float salary_without_sax;
    float salary_with_sax;
    float pay_rate;

    while (1) {
        select = get_select();
            
        if (select == 'q')
            break;
        if (select < 'a' || select > 'd') { 
            printf("Please select between 1 and 5!\n\n");
            continue;
        }

        switch (select) {
            case 'a':
                pay_rate = 8.75;
                break;
            case 'b':
                pay_rate = 9.33;
                break;
            case 'c':
                pay_rate = 10.00;
                break;
            case 'd':
                pay_rate = 11.20;
                break;
        }

        printf("Please enter hours of a week: ");
        scanf("%d", &hours);
        if (hours <= HOUR_BREAK) {
            salary_without_sax = pay_rate * hours;
        } else {
            salary_without_sax = pay_rate * HOUR_BREAK + 
                (hours - HOUR_BREAK) * pay_rate * OVERTIME_RATE;
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
        printf("Salary after tax is %.2f\n\n", salary_with_sax);
    
        while (getchar() != '\n')
            continue;
    }

    return 0;
}

char get_select(void) {
    char select;
    
    printf("Enter the character corresponding to the desired pay rate or action:\n");
    printf("a) $8.75/hr          b) $9.33/hr\n");
    printf("c) $10.00/hr         d) $11.20/hr\n");
    printf("q) quit\n");
    select = getchar();

    while (getchar() != '\n')
        continue;
    
    return select;
}
