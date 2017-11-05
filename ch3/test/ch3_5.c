#include <stdio.h>

int main(void) {
    float second_of_year = 3.156E7f;
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("%d years old equals %e seconds\n", age, age * second_of_year);

    return 0;
}
