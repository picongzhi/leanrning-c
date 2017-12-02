#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUMLEN 10
#define NAMELEN 20
#define ENSNUM 5

struct ensurance {
    char ensurance_num[NUMLEN];
    struct {
        char first_name[NAMELEN];
        char middle_name[NAMELEN];
        char last_name[NAMELEN];
    };
};

char *s_gets(char *st, int n);
void show_ensurance(struct ensurance ensurances[], int count);
void print_ensurance(struct ensurance ensure);

int main(void) {
    struct ensurance ensures[ENSNUM];
    int count = 0;
    int index;

    puts("Please enter ensurance number (empty line to quit):");
    while (count < ENSNUM && s_gets(ensures[count].ensurance_num, NUMLEN) != NULL &&
            ensures[count].ensurance_num[0] != '\0') {
        puts("Now enter first name:");
        s_gets(ensures[count].first_name, NAMELEN);
        puts("And enter middle name:");
        s_gets(ensures[count].middle_name, NAMELEN);
        puts("Last enter last name:");
        s_gets(ensures[count++].last_name, NAMELEN);
        if (count < ENSNUM)
            puts("Now enter next ensurance number:");
    }

    if (count > 0) {
        puts("Here is the list of ensurance member:");
        show_ensurance(ensures, count);
        
        for (index = 0; index < count; index++)
            print_ensurance(ensures[index]);
    }

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

void show_ensurance(struct ensurance ensures[], int count) {
    int index;
    
    for (index = 0; index < count; index++) {
        printf("%s, %s ", ensures[index].first_name,
                ensures[index].last_name);
        if (ensures[index].middle_name[0] != '\0')
            printf("%c.", toupper(ensures[index].middle_name[0]));
        printf(" -- %s\n", ensures[index].ensurance_num);
    }
}

void print_ensurance(struct ensurance ensure) {
    printf("%s, %s ", ensure.first_name, ensure.last_name);
    if (ensure.middle_name[0] != '\0')
        printf("%c.", toupper(ensure.middle_name[0]));
    printf(" -- %s\n", ensure.ensurance_num);
}
