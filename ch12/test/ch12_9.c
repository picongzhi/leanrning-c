#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20


int main(void) {
    int i;
    int n;
    char **words;
    char word[SIZE];

    printf("How many words do you wish to enter? ");
    scanf("%d", &n);
    words = (char **) malloc(n * sizeof(char *));
    
    printf("Enter %d words now:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", word);
        words[i] = (char *) malloc(strlen(word) * sizeof(char));
        strcpy(words[i], word);
    }
    
    puts("Here are your words:");
    for (i = 0; i < n; i++)
        printf("%s\n", words[i]);
    
    free(words);

    return 0;
}
