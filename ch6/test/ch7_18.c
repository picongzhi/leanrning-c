#include <stdio.h>

#define MAX 150

int main(void) {
    int friends = 5;
    int week = 1;
    
    while (friends < MAX) {
        friends = (friends - 1) * 2;
        printf("Week %d, friends %d\n", week, friends);
    }
    printf("Done!\n");

    return 0;
}
