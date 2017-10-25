#include <stdio.h>

void smile(void);

int main(void) {
    int n = 3;
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            smile();
        }
        printf("\n");
    }
    
    return 0;
}

void smile(void) {
    printf("Smile!");
}
