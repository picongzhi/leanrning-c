#include <stdio.h>
#include <string.h>

/* 简单结构 */
struct {
    unsigned int widthValidated;
    unsigned int heightValidated;
} status1;

/* 位域结构 */
struct {
    unsigned int widthValidated : 1;
    unsigned int heightValidated : 1;
} status2;

int main() {
    printf("Memeory size occupied by status1: %lu\n", sizeof(status1));
    printf("Memeory size occupied by status2: %lu\n", sizeof(status2));
    
    return 0;
}
