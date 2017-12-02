#include <stdio.h>
#include <string.h>

#define NAMELEN 20
#define GRADENUM 3
#define CSIZE 4

struct name {
    char first_name[NAMELEN];
    char last_name[NAMELEN];
};

struct student {
    struct name name;
    float grade[GRADENUM];
    float average;
};

void set_student_info(struct student *students);
char *s_gets(char *st, int n);
void count_average(struct student *students);
void show_info(struct student *students);
void print_average(struct student *students);

int main(void) {
    struct student students[CSIZE] = {
        {{"Pi", "Congzhi"}, {0.0, 0.0, 0.0}, 0.0},
        {{"pi", "congzhi"}, {0.0, 0.0, 0.0}, 0.0},
        {{"P", "congzhi"}, {0.0, 0.0, 0.0}, 0.0},
        {{"p", "cz"}, {0.0, 0.0, 0.0}, 0.0}
    };

    set_student_info(students);
    count_average(students);
    show_info(students);
    print_average(students);

    return 0;
}

void print_average(struct student *students) {
    int index;
    float total = 0.0f;;

    for (index = 0; index < CSIZE; index++)
        total += students[index].average;
    printf("Total average: %.2f\n", total / CSIZE);
}

void show_info(struct student *students) {
    int index;
    int count;

    for (index = 0; index < CSIZE; index++) {
        printf("Name: %s %s\n", students[index].name.first_name,
                students[index].name.last_name);
        puts("Grade:");
        for (count = 0; count < GRADENUM; count++)
            printf("%.2f ", students[index].grade[count]);
        printf("\nAverage: %.2f\n\n", students[index].average);
    }
}

void count_average(struct student *students) {
    int index;
    int count;
    float total;

    for (index = 0; index < CSIZE; index++) {
        total = 0.0f;
        for (count = 0; count < GRADENUM; count++) {
            total += students[index].grade[count];
        }
        students[index].average = total / GRADENUM;
    }
}

void set_student_info(struct student *students) {
    int index;
    int count;
    char first_name[NAMELEN];
    char last_name[NAMELEN];

    puts("Enter first name (empty line to stop):");
    while (s_gets(first_name, NAMELEN) != NULL && first_name[0] != '\0') {
        puts("Enter last name:");
        if (s_gets(last_name, NAMELEN) == NULL || last_name[0] == '\0')
            break;
        for (index = 0; index < CSIZE; index++) {
            if (strcmp(first_name, students[index].name.first_name) == 0 &&
                    strcmp(last_name, students[index].name.last_name) == 0) {
                printf("Enter %d grades:\n", GRADENUM);
                for (count = 0; count < GRADENUM; count++) {
                    scanf("%f", &students[index].grade[count]);
                    while (getchar() != '\n')
                        continue;
                }
                break;
            }
        }
        puts("Enter first name:");
    }
    puts("Done.");
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
