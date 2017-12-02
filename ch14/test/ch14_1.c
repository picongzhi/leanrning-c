#include <stdio.h>
#include <string.h>

#define ABBRLEN 4
#define MONLEN 10
#define MONTH 12

struct month {
    char name[MONLEN];
    char abbr[ABBRLEN];
    int days;
    int num;
};

struct month months[12] = {
    {"January", "Jan", 31, 1},
    {"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 30, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}
};

char *s_gets(char *st, int n);

int main(void) {
    int index;
    int total_days;
    char mon[MONLEN];
    
    puts("Enter a month, and you'll get the days since the month.");
    puts("Empty line to quit");

    while (s_gets(mon, MONLEN) != NULL && mon[0] != '\0') {
        total_days = 0;
        for (index = 0; index < MONLEN; index++) {
            total_days += months[index].days;
            if (strcmp(mon, months[index].name) == 0)
                break;
        }
        if (index == MONLEN)
            puts("Not found, enter again:");
        else
            printf("Since %s, total %d days\n", mon, total_days);
    }
    puts("Bye!");

    return 0;
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}
