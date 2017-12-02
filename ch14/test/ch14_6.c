#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAMELEN 20
#define MAXNUM 20
#define FILELEN 20

struct softballer {
    int num;
    char first_name[NAMELEN];
    char last_name[NAMELEN];
    int on_court_times;
    int hit_times;
    int barrier_times;
    int rbi;
    double batting_rate;
};

char *s_gets(char *st, int n);
void show_player(const struct softballer *player);

int main(void) {
    struct softballer player; 
    struct softballer *players[MAXNUM];
    int is_active[MAXNUM];
    int index;
    char filename[FILELEN];
    FILE *fp;
    
    for (index = 0; index < MAXNUM; index++)
        is_active[index] = 0;

    puts("Enter file name:");
    s_gets(filename, FILELEN);
    
    /* open file */
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Can't open %s.", filename);
        exit(1);
    }
    
    /* read data from file by line */ 
    while (fscanf(fp, "%d %s %s %d %d %d %d", 
                &player.num, player.first_name, player.last_name, 
                &player.on_court_times, &player.hit_times, 
                &player.barrier_times, &player.rbi) != EOF) {
        players[player.num] = (struct softballer *) malloc(sizeof(struct softballer));
        *players[player.num] = player;
        players[player.num]->batting_rate = (double) players[player.num]->hit_times / 
            players[player.num]->on_court_times;
        is_active[player.num] = 1;
    }

    /* show players info */
    for (index = 0; index < MAXNUM; index++)
        if (is_active[index])
            show_player(players[index]);

    /* free memory */
    for (index = 0; index < MAXNUM; index++) {
        if (is_active[index])
            free(players[index]);
    }

    /* close file */
    if (fclose(fp) != 0) {
        fprintf(stderr, "Close failed!");
        exit(2);
    }

    return 0;
}

void show_player(const struct softballer *player) {
    printf("Number: %d\n", player->num);
    printf("First name: %s\n", player->first_name);
    printf("Last name: %s\n", player->last_name);
    printf("On court times: %d\n", player->on_court_times);
    printf("Hit times: %d\n", player->hit_times);
    printf("Barrier_times: %d\n", player->barrier_times);
    printf("RBI: %d\n", player->rbi);
    printf("Batting rate: %.2lf\n\n", player->batting_rate);
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find) 
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}
