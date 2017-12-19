#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LEFT 0
#define RIGHT 1
#define CENTER 2

struct font_props {
    unsigned int id: 8;
    unsigned int size: 7;
    unsigned int: 1;
    unsigned int alignment: 2;
    bool bold: 1;
    bool italic: 1;
    bool underline: 1;
};

typedef struct font_props font_props;

void show_font(const font_props font);
char get_choice(void);
void change_font(font_props *font);
void change_size(font_props *font);
void change_alignment(font_props *font);
void toggle_bold(font_props *font);
void toggle_italic(font_props *font);
void toggle_underline(font_props *font);

int main(void) {
    char choice;
    struct font_props font = {1, 12, LEFT, false, false, false};
    
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

void show_font(const font_props font) {
    char *algn = (char *) malloc(6 * sizeof(char)); 
    
    printf(" ID SIZE ALIGNMENT   B   I   U\n");
    printf("%3d %3d", font.id, font.size);
    
    if (font.alignment == LEFT) 
        strcpy(algn, "left");
    else if (font.alignment == RIGHT)
        strcpy(algn, "right");
    else
        strcpy(algn, "center");
    
    printf("%8s    %4s%4s%4s\n", algn, 
            font.bold ? "on" : "off",
            font.italic ? "on" : "off",
            font.underline ? "on" : "off");
    
    free(algn);
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
}

void change_font(font_props *font) {
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

    font->id = id;
}

void change_size(font_props *font) {
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

    font->size = size;
}

void change_alignment(font_props *font) {
    char alignment;

    puts("Select alignment:");
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
            font->alignment = 0;
            break;
        case 'r':
            font->alignment = 1;
            break;
        case 'c':
            font->alignment = 2;
            break;
    }
}

void toggle_bold(font_props *font) {
    font->bold = (font->bold ? false : true);
}

void toggle_italic(font_props *font) {
    font->italic = (font->italic ? false : true);
}

void toggle_underline(font_props *font) {
    font->underline = (font->underline ? false : true);
}
