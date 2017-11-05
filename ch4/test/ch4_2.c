#include <stdio.h>
#include <string.h>

int main(void) {
    char first_name[20];
    char last_name[20];
    int len;

    printf("Please enter your first name and last name: ");
    scanf("%s %s", first_name, last_name);
    len = strlen(first_name) + 3;

    printf("You are: \"%s\", last name: \"%s\"\n",
            first_name, last_name);
    printf("First name: \"%20s\", last name: \"%s\"\n",
            first_name, last_name);
    printf("First name: \"%-20s\", last name: \"%-20s\"\n",
            first_name, last_name);
    printf("You are: \"%*s%s\"\n",
            len, first_name, last_name);

    return 0;
}
