#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LEFT 0x10
#define CENTER 0x20
#define RIGHT 0x30

#define BOLD_MASK 0x1
#define ITALIC_MASK 0x2
#define UNDERLINE_MASK 0x4

#define ID_MASK 0xff0000
#define SIZE_MASK 0x7f00
#define ALIGNMENT_MASK 0x30

void show_font(const unsigned long font);
char get_choice(void);
void change_font(unsigned long *font);
void change_size(unsigned long *font);
void change_alignment(unsigned long *font);
void toggle_bold(unsigned long *font);
void toggle_italic(unsigned long *font);
void toggle_underline(unsigned long *font);

int main(void) {
    /*
    初始状态：00000001 00001100 00010000
    */
    unsigned long font = 0x010c10;
    char choice;

    while (true) {
        show_font(font);
        choice = get_choice();

        if (choice == 'q')
            break;

        switch (choice) {
            case 'f':
                change_font(&font);
                break;
            case 's':
                change_size(&font);
                break;
            case 'a':
                change_alignment(&font);
                break;
            case 'b':
                toggle_bold(&font);
                break;
            case 'i':
                toggle_italic(&font);
                break;
            case 'u':
                toggle_underline(&font);
                break;
            default:
                break;
        }
    }
    puts("Bye!");

    return 0;
}

void show_font(const unsigned long font) {
    char* align = (char *) malloc(6 * sizeof(char));
    int id, size, alignment;

    printf(" ID SIZE ALIGNMENT   B   I   U\n");
    
    id = (ID_MASK & font) >> 16;
    size = (SIZE_MASK & font) >> 8;
    printf("%3d %3d", id, size);

    alignment = ALIGNMENT_MASK & font;
    if (alignment == LEFT)
        strcpy(align, "left");
    else if (alignment == CENTER)
        strcpy(align, "center");
    else if (alignment == RIGHT)
        strcpy(align, "right");

    printf("%8s    %4s%4s%4s\n", align,
            (font & BOLD_MASK) ? "on" : "off",
            (font & ITALIC_MASK) ? "on" : "off",
            (font & UNDERLINE_MASK) ? "on" : "off");

    free(align);
}

char get_choice(void) {
    char choice;

    puts("\nf)change font    s)change size    a)change alignment");
    puts("b)toggle bold      i)toggle italic  u)toggle underline");
    puts("q)quit");
    choice = getchar();
    while (getchar() != '\n')
        continue;

    return choice;

    return 'q';
}

void change_font(unsigned long *font) {
    int id;

    while (true) {
        printf("Enter font id (0-255): ");
        scanf("%d", &id);
        while (getchar() != '\n')
            continue;
        if (id >= 0 && id <= 255)
            break;
        puts("Please enter between 0 and 255");
    }

    *font = ((~ID_MASK) & (*font)) | (id << 16);
}

void change_size(unsigned long *font) {
    int size;

    while (true) {
        printf("Enter font size (0-127): ");
        scanf("%d", &size);
        while (getchar() != '\n')
            continue;
        if (size >= 0 && size <= 127)
            break;
        puts("Please enter between 0 and 127");
    }

    *font = ((~SIZE_MASK) & (*font)) | (size << 8);
}

void change_alignment(unsigned long *font) {
    char alignment;

    puts("Select alignment: ");
    puts("l)left   c)center   r)right");

    while (true) {
        alignment = getchar();
        while (getchar() != '\n')
            continue;
        if (alignment == 'l' || alignment == 'c' ||
                alignment == 'r')
            break;
        puts("Select l, c or r");
    }

    switch (alignment) {
        case 'l':
            *font = ((~ALIGNMENT_MASK) & (*font)) | LEFT;
            break;
        case 'c':
            *font = ((~ALIGNMENT_MASK) & (*font)) | CENTER;
            break;
        case 'r':
            *font = ((~ALIGNMENT_MASK) & (*font)) | RIGHT;
            break;
    }
}

void toggle_bold(unsigned long *font) {
    *font = BOLD_MASK ^ (*font);
}

void toggle_italic(unsigned long *font) {
    *font = ITALIC_MASK ^ (*font);
}

void toggle_underline(unsigned long *font) {
    *font = UNDERLINE_MASK ^ (*font);
}
