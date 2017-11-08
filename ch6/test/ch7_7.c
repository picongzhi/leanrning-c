#include <stdio.h>
#include <string.h>

#define LEN 40

int main(void) {
    char word[LEN];
    int i, len;
    printf("Please enter a word: ");
    scanf("%s", word);
    
    len = strlen(word);
    for (i = len - 1; i >= 0; i--)
        printf("%c", word[i]);
    printf("\n");

    return 0;
}
