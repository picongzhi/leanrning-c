#include <stdio.h>

int main(void) {
    char first_name[20];
    char last_name[20];

    printf("Please enter your first name and last name: ");
    scanf("%s %s", first_name, last_name);
    printf("You are %s,%s\n", first_name, last_name);

    return 0;
}
