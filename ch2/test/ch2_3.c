#include <stdio.h>

int main(void) {
    int age;
    int days;
    
    scanf("%d", &age);
    days = age * 365;
    printf("You are %d years old, and it's %d days.\n", age, days);

    return 0;
}
