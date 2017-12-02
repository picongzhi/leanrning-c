#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    {"February", "Feb", 27, 2},
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
int is_leap_year(int year);
int is_date_leagal(int day, char *month, int year);

int main(void) {
    int index;
    int total_days = 0;
    int day, year, mons;
    char mon[MONLEN];
    
    puts("Enetr the day:");
    scanf("%d", &day);
    while (getchar() != '\n')
        continue;
    puts("Enetr the month:");
    s_gets(mon, MONLEN);
    puts("Enter the year:");
    scanf("%d", &year);
    
    if ((mons = is_date_leagal(day, mon, year)) == 0) {
        puts("Invalid date fomat");
        exit(1);
    }
    
    for (index = 0; index < mons - 1; index++) 
        total_days += months[index].days;

    if (is_leap_year(year) && index > 1)
        total_days += 1;
    total_days += day;
    printf("Total %d days in %d-%s-%d\n", total_days, year, mon, day);

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

int is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) ||
            year % 400 == 0)
        return 1;
    return 0;
}

int is_date_leagal(int day, char *month, int year) {
    int index;
    
    for (index = 0; index < MONTH; index++) {
        if (strcmp(month, months[index].name) == 0 ||
                strcmp(month, months[index].abbr) == 0 ||
                (atoi(month) > 0 && atoi(month) == months[index].num))
            break;
    }

    if (index == MONTH)
        return 0;
    if (day > 0 && day <= months[index].days && year > 0)
        return index + 1;
    else
        return 0;
}
