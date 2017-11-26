#include <stdio.h>

#include "pe12-3a.h"

int main(void) {
    int mode;
    int temp;
    int distance;
    double fuel;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &temp);
    while (temp >= 0) {
        set_mode(temp, &mode);
        get_info(mode, &distance, &fuel);
        show_info(mode, distance, fuel);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &temp);
    }
    printf("Done.\n");

    return 0;
}
