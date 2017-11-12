#include <stdio.h>

int main(void) {
    char ch;
    int lower_count, upper_count;
    lower_count = upper_count = 0;
    
    while ((ch = getchar()) != EOF) {
        if (ch >= 'a' && ch <= 'z')
            lower_count++;
        else if (ch >= 'A' && ch <= 'Z')
            upper_count++;
    }

    printf("Upper case count %d\n", upper_count);
    printf("Lower case count %d\n", lower_count);

    return 0;
}
