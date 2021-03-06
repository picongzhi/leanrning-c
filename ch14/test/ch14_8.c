#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NAMELEN 20
#define SEATNUM 12

struct flight {
    int num;
    bool is_ordered;
    char first_name[NAMELEN];
    char last_name[NAMELEN];
};

char *s_gets(char *st, int n);
char show_menu(void);
void eatline(void);
void show_empty_number(const struct flight *fly);
void show_empty_list(const struct flight *fly);
void show_alphabetical_list(const struct flight *fly);
void assign_seat(struct flight *fly);
void delete_seat(struct flight *fly);
void show_flight(const struct flight *fly);
void init_flight(struct flight *fly);

int main(void) {
    char choice;
    struct flight fly[SEATNUM];
   
    init_flight(fly);

    while (1) {
        choice = show_menu();
        
        if (choice == 'f')
            break;

        switch (choice) {
            case 'a':
                show_empty_number(fly);
                break;
            case 'b':
                show_empty_list(fly);
                break;
            case 'c':
                show_alphabetical_list(fly);
                break;
            case 'd':
                assign_seat(fly);
                break;
            case 'e':
                delete_seat(fly);
                break;
            default:
                puts("Please select from a~f");
                break;
        }
    }
}

void show_flight(const struct flight *fly) {
    int index;
    
    for (index = 0; index < SEATNUM; index++)
        printf("No.%d Ordered: %c First name: %s Last name: %s\n", 
                fly[index].num, fly[index].is_ordered ? 'y' : 'n',
                fly[index].first_name, fly[index].last_name);
}

void init_flight(struct flight *fly) {
    int index;

    for (index = 0; index < SEATNUM; index++) {
        fly[index].num = index;
        fly[index].is_ordered = false;
        strcpy(fly[index].first_name, "");
        strcpy(fly[index].last_name, "");
    }
}

void show_empty_number(const struct flight *fly) {
    int index;
    int count = 0;

    for (index = 0; index < SEATNUM; index++)
        if (!fly[index].is_ordered)
            count++;
    
    printf("Empty seat number: %d\n", count);
}

void show_empty_list(const struct flight *fly) {
    int index;

    for (index = 0; index < SEATNUM; index++)
        if (!fly[index].is_ordered)
            printf("%d ", fly[index].num);

    printf("\n");
}

void show_alphabetical_list(const struct flight *fly) {
    show_flight(fly);
}

void assign_seat(struct flight *fly) {
    int num;

    show_empty_list(fly);

    puts("Please select a number (q to return):");
    if (scanf("%d", &num) != 1) {
        eatline();
        return;
    }
    eatline();

    puts("Enter first name (empty line to return):");
    if (s_gets(fly[num].first_name, NAMELEN) == NULL ||
            fly[num].first_name[0] == '\0') {
        strcpy(fly[num].first_name, "");
        return;
    }
    
    puts("Now enter last name (empty line to return):");
    if (s_gets(fly[num].last_name, NAMELEN) == NULL ||
            fly[num].last_name[0] == '\0') {
        strcpy(fly[num].first_name, "");
        strcpy(fly[num].last_name, "");
        return;
    }

    fly[num].is_ordered = true;
    printf("You have orderd No.%d seat\n", fly[num].num);
}

void delete_seat(struct flight *fly) {
    int num;
    char first_name[NAMELEN];
    char last_name[NAMELEN];

    puts("Please enter first name (empty line to return):");
    if (s_gets(first_name, NAMELEN) == NULL || 
            first_name[0] == '\0') 
        return;

    puts("Now enter last name (empty line to return):");
    if (s_gets(last_name, NAMELEN) == NULL ||
            last_name[0] == '\0')
        return;
    
    puts("Enter the seat number (q to stop):");
    if ((scanf("%d", &num) == 1) && (num >= 0 && num < SEATNUM))
        eatline();
    else {
        eatline();
        return;
    }
    
    if (strcmp(first_name, fly[num].first_name) == 0 && 
            strcmp(last_name, fly[num].last_name) == 0) {
        fly[num].is_ordered = false;
        puts("Delete success");
    } else {
        puts("You don't have permission!");
        return;
    }
}

void eatline(void) {
    while (getchar() != '\n')
        continue;
}

char show_menu(void) {
    char choice;

    puts("To choose a function, enter this letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Quit");

    choice = getchar();
    eatline();

    return choice;
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
