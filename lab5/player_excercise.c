#include <stdio.h>
#include <stdlib.h>
#include "Player.h"
#include "Player.c"

Player * entry_2_player(char *entry){
    printf("entry_2_player(%s) ", entry);
    Player *p = malloc(sizeof(Player));
    sscanf(entries[i], "%s %d", p[num]->name, &p[num]->score);
    return p;
}

int main(void){
    Player **players = NULL,
            *pPlayer;

    int num = 0;
    char *entries[] = {"Sam 12", "Fil 34", "Jil 56", "Lil 78", "Bil 90", ""};

    players = malloc(10*sizeof(Player*));
    printf("players malloc-ated at 0x%p\n", players);
    char * entry = "Sam 46";


    for (int i = 0; *entries[i] != 0; i++){ // indexs: entries[i], players[num]
        players[num] = malloc(sizeof(Player));
        sscanf(entries[i], "%s %d", players[num]-> name, &players[num]->score);
        printf("%d. players[%d] at: 0x%p", i, num, players[num]);
        show_Player("", players[num]);
        num++;
        //pause("Line 45:");
    }

    for (int i = 0; *entries[i] !=0; i++){
        entry_2_player(entry);
        //printf("%d. players[%d] at: 0x%p", i, num, players[num]);
        show_Player("Line 509 check", players[num]);
        num++;
        //pause("Line 45.");

    }

    printf("freeing mallocated memory...")
    for(int i = 0; i < num; i++){
        free(players[i]);
        players[i] = NULL; //so pointer is not freed to system and filled with gibberish
    }
    show_Players("Players[0]: ", players[0]);
    free(players);
    printf("Done !/n");
    
    return 0;
}