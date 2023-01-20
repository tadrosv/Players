#ifndef PLAYER_H
#define PLAYER_H  

#include <stdio.h>
#include <stdlib.h>

// Room for a short name string in Player:
#define NAME_SIZE  	10
// Incremental number of memory, in units of pointers, by which to increase
// size of Player pointer array:
#define MALLOC_INCR	 5

typedef struct {
	char name[NAME_SIZE] ;
	int  score ;
} Player ;

//=========================== MILESTONE 1 FUNCTIONS ===========================

/* If p != NULL, this creates string s from Player *p; e.g. "Sam 56", and
   returns s; if p == NULL, this returns "NULL"
REF: https://en.cppreference.com/w/c/io/fprintf                              */
char *str_Player(Player *p, char s[]) ;

/* Displays s, then displays name and score from p, or "NULL" if p is NULL
   e.g. Player p1 = { "Robin", 78 } ;
        show_Player("Here is our winner: ", &p1) ;
        displays: Here is our winner: "Robin", 78                            */
void show_Player(char *s, Player *p) ;

/* Displays s, then calls show_Player() for each of num Player's from p.     */
void show_Players(char *s, Player *p[], int num) ;

/* This expects a string entry, consisting of a name, space, and an int score.
   When entry is "Sam 67", this function:
   1) displays 'malloc() for "Sam 67" ...'
   2) attempts malloc() for a Player
   3) if malloc() fails, the function displays: 'Failed! Returning NULL'
   4) attempts to convert entry with *n = sscanf(...) to name and score of a
      Player variable. If successful, indicated by *n = 2, displays
      'at address: 0x000....' and returns its address.
   5) if entry is not valid, e.g. "Sam45", this function free the allocated memory,
      and displays 'Invalid entry string! Returning NULL', and returns NULL.
REF: https://en.cppreference.com/w/c/io/fscanf                               */
Player * entry2_Player(char *entry, int *n) ;

/* This repeatedly prompts user to enter a name and score, e.g. "Sam 45", calls
   on entry2_Player() to attempt to convert this into a malloc'd Player, until
   user enters valid name and score. Once successful, it returns a new Player*.
   If user enters nothing, then this returns NULL.                           */
Player * get_Player() ;

/* This displays string s, then:
   if p == NULL, it displays 'Nothing to free!'
   else it displays the address p, frees p, and returns NULL.                */
Player * free_Player(char *s, Player *p) ;

/* Returns a pointer to allocated array intended to hold num Player* pointers.
   If unsuccessful, this returns NULL                                        */
Player ** create_Player_array(int num) ;

/* This free()s num Player's previously allocated via the players array, and
   assumes there are no more than num Player's allocated, and sets each of
   the num entries to NULL.                                                  */
Player ** clear_Player_array(Player ** players, int num) ;

/* This first checks that all size pointers in array players are NULL. If not,
   then this displays a message "NOT ALL POINTERS ARE NULL. CAN'T FREE THIS."
   and returns players.  If all pointers are NULL, then this free()s the array
   previously allocated via players, and returns NULL                        */
Player ** release_Player_array(Player ** players, int size) ;

/* This stores p to players[*num], increments *num, and if *num % MALLOC_INCR == 0
then it realloc'ates players with room for an extra MALLOC_INCR entries, and
returns the new realloc'ated address. Thus, *num = number of entries so far in
array *players, and the size of array *players[] is increased in increments of
MALLOC_INCR.
e.g. players = add_Player(players, player, &num, &size) ;             */
Player ** add_Player(Player *players[], Player *p, int *num, int *size) ;


//=========================== MILESTONE 2 FUNCTIONS ===========================

/* Returns -1 / 0 / +1 if p1->name is < , == , or > p2->name
   This function is passed as the fourth argument to qsort().                */
int cmp_Player_name(Player **p1, Player **p2);

/* Returns -1 / 0 / +1 if p1->score is < , == , or > p2->score
   This function is passed as the fourth argument to qsort().                */
int cmp_Player_score(Player **p1, Player **p2);

/* Uses qsort to sort array players of num Player* pointers. If how = 'n', it
   it sorts by name. If how = 's', it sorts by score. It returns players.
REF:  https://en.cppreference.com/w/cpp/algorithm/qsort                      */
Player ** sort_Players(Player **players, int num, char how) ;

/* Returns -1 / 0 / +1 if key is < , == , or > p->name
   This function is passed as the fifth argument to bsearch().               */
int cmp_key_name(char *key, Player **p) ;

/* Returns -1 / 0 / +1 if key is < , == , or > p->score
   This function is passed as the fifth argument to bsearch().               */
int cmp_key_score(int *key, Player **p) ;

//#undef PLAYER_H
#endif
