#include <stdio.h>

int get_position_bit(int value, int position);

int main(void) {
    int value, position;

    puts("Enter a value and a position:");
    scanf("%d %d", &value, &position);

    printf("Bit in position %d is %d\n", 
            position, get_position_bit(value, position));
    
    return 0;
}

int get_position_bit(int value, int position) {
    int i = 1;

    while (i++ < position) {
        value >>= 1;
    }

    return value & 01;
}
