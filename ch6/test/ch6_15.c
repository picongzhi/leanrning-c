#include <stdio.h>
#include <string.h>

#define MAX 256

int main(void) {
    int i;
    int len;
    char arr[MAX];

    printf("Please enter something: ");
    scanf("%s", arr);
    len = strlen(arr);

    for (i = len; i >= 0; i--)
        printf("%c", arr[i]);
    printf("\n");

    return 0;
}
