#include <stdio.h>

int main(void) {
    int i = 2147483647;
    float j = 3.4E38f;
    float k = 0.1234567f;
    
    printf("i = %d, i + 1 = %d\n", i, i + 1);
    printf("j = %f, j * 100 = %f\n", j, j * 100.0f);
    printf("k = %f, k / 10 = %f\n", k, k / 2.0f);

    return 0;
}
