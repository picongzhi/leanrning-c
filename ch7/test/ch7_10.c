#include <stdio.h>

#define SINGLE_BREAK 17850
#define HOUSEHOLD_BREAK 23900
#define MARRIED_BREAK 29750
#define DIVORCE_BREAK 14875

#define LOW_RATE 0.15
#define HIGH_RATE 0.28

int main(void) {
    int type;
    float tax;
    float income;

    while (1) {
        printf("Please select your type:\n");
        printf("1) Single\n2) Household\n3)Married\n4) Divorced\n");
        printf("5) quit\n");
        scanf("%d", &type);

        if (type < 1 || type > 5) {
            printf("Invalid selection, please enter again!\n");
            continue;
        }
        if (type == 5)
            break;

        printf("Please enter your income: ");
        scanf("%f", &income);
        switch (type) {
            case 1:
                if (income < SINGLE_BREAK)
                    tax = income * LOW_RATE;
                else
                    tax = SINGLE_BREAK * LOW_RATE + 
                        (income - SINGLE_BREAK) * HIGH_RATE;
                break;
            case 2:
                if (income < HOUSEHOLD_BREAK)
                    tax = income * LOW_RATE;
                else
                    tax = HOUSEHOLD_BREAK * LOW_RATE +
                        (income - HOUSEHOLD_BREAK) * HIGH_RATE;
                break;
            case 3:
                if (income < MARRIED_BREAK)
                    tax = income * LOW_RATE;
                else
                    tax = MARRIED_BREAK * LOW_RATE +
                        (income - MARRIED_BREAK) * HIGH_RATE;
                break;
            case 4:
                if (income < DIVORCE_BREAK)
                    tax = income * LOW_RATE;
                else
                    tax = DIVORCE_BREAK * LOW_RATE +
                        (income - DIVORCE_BREAK) * HIGH_RATE;
                break;
            default:
                break;
        }
        printf("Your tax is %2.f\n", tax);
    }
    printf("Bye!\n");
}
