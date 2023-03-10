/******************************************************************************
Victor Tadros
CMPT 201 X01L
Instructor: Hanan Saleh

FROM LAB SPECS:
Milestone 1: [60]
 1. [ 2  ] str_Player()
 2.	[ 2+1] show_Player()
 3. [ 4+1] show_Players()
 4. [ 9+1] entry2_Player()
 5. [ 9+1] get_Player()
 6.	[ 4+1] free_Player()
 7.	[ 4+1] create_Player_array()
 8.	[ 9+1] add_Player()
 9. [ 4+1] clear_Player_array()
10. [ 4+1] release_Player_array()

Milestone 2: [40]
 1.	[ 4+1] cmp_Player_name()
 2.	[ 4+1] cmp_Player_score()
 3.	[ 6+4] sort_Players()
 4.	[ 8+2] cmp_key_name and binary search by name
 5.	[ 8+2] cmp_key_score and binary search by score

CODE SECTIONS:
Milestone 1:
 1. str_Player() and show_Player()
 2. show_Players()
 3. entry2_Player()
 4. get_Player() and free_Player()
 5. create_Player_array()
 6. add_Player()
 7. clear_Player_array()
 8. release_Player_array()

Milestone 2:
 9. create Player** array
10. sort_Players() and cmp_Player_name()
11. cmp_key_name and binary search by name
12. cmp_Player_score()
13. cmp_key_score and binary search by score
14. clear_Player_array() and release_Player_array()
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Player.h"

//#############################################################################
char pause(char *s) {
  printf("%sPress ENTER ... ", s);
  fflush(stdin);
  return getchar();
}

//#############################################################################
int main() {

//============================== MILESTONE 1 CODE =============================
  printf("\n--------------------------------------------------------------\n"
	 "1. str_Player() and show_Player()\n");
  
  Player p1 = {"Jane", 67};
  char s[15];
  str_Player(&p1, s);
  show_Player("Here is player: ", &p1);

  pause("Pause ... ") ;

//=============================================================================
  printf("\n--------------------------------------------------------------\n"
	 "2. show_Players()\n");
  int p_count = 0;
  Player p2 = {"Sam", 56};
  Player p3 = {"Dan", 74};
  Player *choose_a_name[20];
  choose_a_name[p_count++] = &p1;
  choose_a_name[p_count++] = &p2;
  choose_a_name[p_count++] = &p3;
  show_Players("Here are the players: ", choose_a_name, 3);
  
  pause("Pause ... ") ;

//=============================================================================
  printf("\n--------------------------------------------------------------\n"
	       "3. entry2_Player()\n");
  
  
  int num = 0;
  Player *p4 = entry2_Player("Robin 78", &num);
  choose_a_name[p_count++] = p4;
  Player *p5 = entry2_Player("Don 22", &num);
  choose_a_name[p_count++] = p5;
  show_Players("Here are the players:\n", choose_a_name, 5);
  
  pause("Pause ... ") ;

//=============================================================================
  printf("\n--------------------------------------------------------------\n"
	 "4. get_Player() and free_Player()\n");
  
  Player * p6 = get_Player();
  Player * p7 = get_Player();
  choose_a_name[p_count++] = p6;
  choose_a_name[p_count++] = p7;
  show_Players("Here are the players:\n", choose_a_name, 7);
  for( int i = 6; 2 < i; i--){ 
    free_Player("Freeing player...", choose_a_name[i]);
  }
  
  pause("Pause ... ") ;

//=============================================================================
  printf("\n--------------------------------------------------------------\n"
	 "5. create_Player_array()\n");
  
  Player ** players = NULL;
  int n = 0;  
  players = create_Player_array(5);
  show_Players("Contents of players: ", players, 0);
  printf("\n");
  char *init[] = { "Sue 43", "Andrew 32", "Man 12" };
  for (int i = 0; i < 3; i++){
    players[i] = entry2_Player(init[i], &n);
  }
  
  show_Players("Contents of players: ", players, 3);
  
  pause("Pause ... ") ;

//=============================================================================
  printf("\n--------------------------------------------------------------\n"
	 "6. add_Player()\n");
  
  char *new_p[] =  { "Sam 56", "Janet 64", "Bob 6" };
  int init_size = 5, entries = 3;
  for ( int i = 0; i < 3; i++ ){
    players = add_Player(players, entry2_Player(new_p[i], &n), &entries, &init_size);
  }
  show_Players("Contents of players: ", players, 6);
  
  pause("Pause ... ") ;
  
//=============================================================================
  printf("\n--------------------------------------------------------------\n"
	 "7. clear_Player_array()\n");
  
  clear_Player_array(players, 6);
  
  pause("Pause ... ") ;
  
//=============================================================================
  printf("\n--------------------------------------------------------------\n"
	 "8. release_Player_array()\n");

  release_Player_array(players, 10);
  
  pause("Pause ... ") ;

//============================== MILESTONE 2 CODE =============================
  printf("\n--------------------------------------------------------------\n"
	 "9. create Player** array\n");
  
  Player **players2 = NULL;
  players2 = create_Player_array(14);
  int entries2 = 0, init_size2 = 14;  
  char * p_array[] = { "Sam 12", "Fil 34", "Jil 56", "Lil 78", "Bil 90",
		       "Ned 21", "Rik 43", "Wil 65", "Dan 87", "Jen 95",
		       "Deb 31", "Man 52", "Ted 72" };
    //{ "Bil 45", "Sam 12", "Fil 34", "Wil 56" };
  
  for ( int i = 0; i < 13; i++){
    add_Player(players2, entry2_Player(p_array[i], &n), &entries2, &init_size2);
  }
  show_Players("These are the players:\n", players2, 13);
  
  pause("Pause ... ") ;

//=============================================================================
  printf("\n--------------------------------------------------------------\n"
	 "10. sort_Players() and cmp_Player_name()\n");

  sort_Players(players2, 13, 'n');
  show_Players("These are the players sorted by name:\n", players2, 13);

  pause("Pause ... ") ;

//=============================================================================
  printf("\n--------------------------------------------------------------\n"
	 "11. cmp_key_name and binary search by name\n");
  
  Player ** pl;
  char *key_n[5] = { "Wil", "Jen", "Sue", "Bil", "Ike"};
  for (int i=0 ; i < 5 ; i++) {
    printf("Searching for name \"%s\" ... ", key_n[i]) ;
    pl = bsearch(key_n[i], players2, 13, sizeof(Player*), cmp_key_name);
    if (pl != NULL)
      printf("Found: %s, %d\n", (*pl)->name, (*pl)->score) ;
    else
      printf("Not found !\n") ;	
  }

  pause("Pause ... ") ;

//=============================================================================
  printf("\n--------------------------------------------------------------\n"
	 "12. cmp_Player_score()\n");

  sort_Players(players2, 13, 's');
  show_Players("These are the players sorted by score:\n", players2, 13);
	
  pause("Pause ... ") ;

//=============================================================================
  printf("\n--------------------------------------------------------------\n"
	 "13. cmp_key_score and binary search by score\n");

  int key_s[5] = { 87, 24, 91, 52, 12 };
  for (int i = 0; i < 5; i++){
    printf("Searching for score = %d ... ", key_s[i]);
    pl = bsearch(&key_s[i], players2, 13, sizeof(Player*), cmp_key_score);
    if (pl != NULL)
      printf("Found: %s, %d\n", (*pl)->name, (*pl)->score) ;
    else
      printf("Not found !\n") ;
  }
  pause("Pause ... ") ;

//=============================================================================
  printf("\n--------------------------------------------------------------\n"
	 "14. clear_Player_array() and release_Player_array()\n");

  clear_Player_array(players2, 13);
  release_Player_array(players2, init_size2);


  pause("Pause ... ") ;


  return 0;
}

//#############################################################################

