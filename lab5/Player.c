/*
Victor Tadros
CMPT 201 X01L
Instructor: Hanan Saleh
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Player.h"

//#############################################################################

//============================== MILESTONE 1 CODE =============================

char *str_Player(Player *p, char s[]){
  if (p != NULL){
    sprintf(s, "%s %d", p->name, p->score);
    return s;
  }
  else
    return NULL;
}

//=============================================================================

void show_Player(char *s, Player *p){
  if (p != NULL)
    printf("%s%s, %d\n", s, p->name, p->score);
  else
    printf("NULL");
}

//=============================================================================

void show_Players(char *s, Player *p[], int num){
  printf("%s\n", s);
  for (int i = 0; i < num; i++){
    printf("%2d. ", i);
    show_Player("", p[i]);
  }
}

//=============================================================================

Player * entry2_Player(char *entry, int *n){
  
  printf("Displays malloc for %s...\n", entry);
  Player *p = (Player *)malloc(sizeof(Player));

  *n = sscanf(entry, "%s %d", p->name, &(p->score));
  
  if (*n != 2){
    free(p);
    printf("Invalid entry string! Returning NULL\n");
    return NULL;
  }

  else if (p == NULL){
    printf("Failed! Returning NULL\n");
    return NULL;
  }
  
  else{
    printf("at address: %p\n", p);
    return p;
  }
}

//=============================================================================

Player * get_Player(){
  int m = 0;
  int *n = &m;
  char entry[15];
  Player * res;
  while (*n!=2){
    fgets(entry, 15, stdin);
    if (strlen(entry) == 1)
      return NULL;
    else
      break;
  }
  res = entry2_Player(entry, n);
  return res;  
}

//=============================================================================

Player * free_Player(char *s, Player *p){
  printf("\n%s\n", s);
  if (p != NULL){
    printf("Free'd at address: %p\n", p);
    free(p);
    p = NULL;
    return p;
  }
  else{
    printf("Nothing to free!\n");
    return p;
  }
}

//=============================================================================

Player ** create_Player_array(int num){
  Player **players = NULL;
  players = malloc(num * sizeof(Player*));
  if (players == NULL)
    return NULL;
  else{
    for(int i = 0; i < num; i++){
      players[i] = NULL;
    } 
    return players;
  }
}

//=============================================================================

Player ** add_Player(Player *players[], Player *p, int *num, int *size){	
  players[*num] = p;
  *num += 1;
  if (*num == *size){
    players = realloc(players, (*size + MALLOC_INCR)* sizeof(Player*));
    *size += MALLOC_INCR;
  }
  return players;
}

//=============================================================================

Player ** clear_Player_array(Player ** players, int num){
  char s[15];
  for (int i = 0; i < num; i++){	
    if (players[i] != NULL){ 
    free_Player(str_Player(players[i], s), players[i]);
    players[i] = NULL; //so pointer is not freed to system and filled with gibberish
    }
  }
  return players;
}

//=============================================================================

Player ** release_Player_array(Player ** players, int size){
  for (int i = 0; i < size; i++){
    if (players[i] != NULL) {
      printf("NOT ALL POINTERS ARE NULL. CAN'T FREE THIS.\n");
      return players;
    }
  }
  free(players);
  players = NULL;
  return players;
}

//============================== MILESTONE 2 CODE =============================

int cmp_Player_name(Player **p1, Player **p2){
  return strcmp((*p1)->name, (*p2)->name);
}

//=============================================================================

int cmp_Player_score(Player **p1, Player **p2){
  return ((*p1)->score < (*p2)->score ? -1: (*p1)->score > (*p2)->score ? 1 : 0);
}

//=============================================================================

Player ** sort_Players(Player **players, int num, char how){
  if (how == 'n')
    qsort(players, num, sizeof(Player*), cmp_Player_name);
  else if (how == 's')
    qsort(players, num, sizeof(Player*), cmp_Player_score);
  return players;

}

//=============================================================================

int cmp_key_name(char *key, Player **p) {
  int x = strcmp(key, (*p)->name);
  return (x < 0 ? -1 : x > 0 ? 1 : 0); 
}
//=============================================================================

int cmp_key_score(int *key, Player **p){
  return (*key < (*p)->score ? -1: *key > (*p)->score ? 1 : 0);
}

//#############################################################################

