#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    char cur, prev;
    bool is_word = false;
    int word_count, character_count;
    word_count = character_count = 0;
    prev = ' ';

    while ((cur = getchar()) != EOF) {
        if ((isspace(prev) || ispunct(prev)) &&
                (!isspace(cur) && !ispunct(cur))) {
            is_word = true;
            word_count++;
        } else if ((isspace(cur) || ispunct(cur)) &&
                (!isspace(prev) && !ispunct(prev)))
            is_word = false;
        
        if (is_word)
            character_count++;
        prev = cur;
    }
    printf("Average length of word is %.2f\n", 
            (float) character_count / word_count);

    return 0;
}
