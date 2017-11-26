#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_n_dice(int, int);

int main(void) {
    int dice;
    int roll;
    int sides;
    int sets;
    int i;

    srand((unsigned int) time(0));
    printf("Enter the number of sets; enter q to stop: ");
    while (scanf("%d", &sets) == 1) {
        printf("How many sides and how many dice? ");
        scanf("%d %d", &sides, &dice);
        
        printf("Here are %d sets of %d %d-sided throws.\n",
                sets, dice, sides);
        for (i = 0; i < sets; i++) {
            roll = roll_n_dice(dice, sides);
            if (roll < 0)
                break;
            printf("%d ", roll_n_dice(dice, sides));
        }
        printf("\nHow many sets? Enter q to stop: ");

        while (getchar() != '\n')
            continue;
    }

    return 0;
}

int roll_n_dice(int dice, int sides) {
    int d;
    int total = 0;
    if (sides < 2) {
        printf("Need at least 2 sides.\n");
        return -2;
    }
    if (dice < 1) {
        printf("Need at least 1 die.\n");
        return -1;
    }

    for (d = 0; d < dice; d++)
        total += rand() % sides + 1;

    return total;
}
