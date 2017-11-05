#include <stdio.h>

int main(void) {
    float speed;
    float file_size;
    
    printf("Please enter download speed and file size: ");
    scanf("%f %f", &speed, &file_size);
    printf("At %.2f megabits per second, a file of %.2f megabytes\n",
            speed, file_size);
    printf("downloads in %.2f seconds\n", 8.0 * file_size / speed);

    return 0;
}
