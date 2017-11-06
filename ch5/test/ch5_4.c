#include <stdio.h>

#define CM_TO_FOOT 30.48
#define FOOT_TO_INCH 12

int main(void) {
    float height;
    int feet;
    float inches;
    printf("Enter a height in centimeters (<=0 to quit): ");
    scanf("%f", &height);
    
    while (height > 0) {
        feet = height / CM_TO_FOOT;
        inches = (height - (CM_TO_FOOT * feet)) / CM_TO_FOOT * FOOT_TO_INCH;
        printf("%.1f cm = %d feet, %.1f inches\n",
                height, feet, inches);
        printf("Enter a height in centimeters (<=0 to quit): ");
        scanf("%f", &height);
    }
    printf("Done!\n");

    return 0;
}
