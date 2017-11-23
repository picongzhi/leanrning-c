#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch;
    int word_cnt, upper_letter_cnt, lower_letter_cnt, punct_cnt, num_cnt;
    word_cnt = upper_letter_cnt = lower_letter_cnt = punct_cnt = num_cnt = 0;
    int in_word = 0;

    puts("Please enter some text (EOF to stop): ");
    while ((ch = getchar()) != EOF) {
        if (!isspace(ch))
            in_word = 1;
        else 
            if (in_word)
                word_cnt++;

        if (isupper(ch))
            upper_letter_cnt++;
        else if (islower(ch))
            lower_letter_cnt++;
        else if (ispunct(ch))
            punct_cnt++;
        else if (isdigit(ch))
            num_cnt++;
    }
    printf("World: %d, Upper case: %d, Lower case: %d, punct: %d, number: %d\n",
            word_cnt, upper_letter_cnt, lower_letter_cnt, punct_cnt, num_cnt);

    return 0;
}
