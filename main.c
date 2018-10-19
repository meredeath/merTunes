#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "musiclist.h"
#include "musiclib.h"

int main(){

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Making a musiclist and testing print: \n");
  struct song_node * n0 = malloc(sizeof(struct song_node));
  char c0[100] = "Star Spangled Banner";
  strncpy(n0->name,(char *)&"Star",100);
  char a0[100] = "Francis Scott Key";
  strncpy(n0->artist,a0,100);
  print_list(n0);

  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Testing insert front:\n");
  n0 = insert_front(n0,"Never Gonna Give You Up","Rick Astley");
  print_list(n0);

  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Testing compare:\n");
  struct song_node * n1 = malloc(sizeof(struct song_node));
  strncpy(n1->name,(char *)&"Star",100);
  strncpy(n1->artist,(char *)&"Rick Astley",100);
  printf("%d\n", compare(n0,n1));
  printf("%d\n", compare(n0->next,n1));

  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Testing insert ordered: \n");
  n0 = insert_ordered(n0,"Can't Stop The Feeling", "Justin Timberlake");
  n0 = insert_ordered(n0, "Monster", "Lady Gaga");
  n0 = insert_ordered(n0, "Monster", "Rihanna");
  n0 = insert_ordered(n0, "Pon De Replay", "Rihanna");
  print_list(n0);
  struct song_node * n2 = new_node("Let it Go","Idina Menzel");
  n2 = insert_ordered(n2, "Life Is A Highway", "Rascal Flatts");
  print_list(n2);

  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Testing random: \n");
  struct song_node *r = return_rand(n0);
  print_single(r);

  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Testing find_node: \n");
  struct song_node *found = find_node(n0, "Monster", "Lady Gaga");
  print_single(found);
  struct song_node *not = find_node(n0, "Turn Down For What", "Lil Jon");
  print_list(not);

  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Testing find_first_song: \n");
  struct song_node *JT = first_song_of(n0, "Justin Timberlake");
  print_single(JT);
  struct song_node *rihanna = first_song_of(n0, "Rihanna");
  print_single(rihanna);
  struct song_node *yikes = first_song_of(n0, "Bob Ross");
  print_single(yikes);

  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Testing remove_node: \n");
  struct song_node *killed = remove_node(n0, "Monster", "Lady Gaga");
  print_list(killed);
  struct song_node *killed2 = remove_node(n0, "Can't Stop The Feeling", "Justin Timberlake");
  print_list(killed2);
  struct song_node *alive = remove_node(n0, "Turn Down For What", "Lil Jon");
  print_list(alive);

  free_list(n0);
  free_list(n1);
  free_list(n2);

  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Making a music library, adding some songs, and printing: \n");
  struct song_node *mlib[27];
  for(int i = 0;i<27;i++) {
    mlib[i]=NULL;
  }
  add_song(mlib, "abcd", "ef");
  print_lib(mlib);
  add_song(mlib, "acd", "*efg");
  print_lib(mlib);
  add_song(mlib, "blah", "0ef");
  print_lib(mlib);
  add_song(mlib, "bleh", "befg");
  print_lib(mlib);
  add_song(mlib, "meh", "bexf");
  print_lib(mlib);
  add_song(mlib, "abd", "aef");
  print_lib(mlib);

  /*
  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Clearing the music library :( : \n");
  clear(mlib);
  print_lib(mlib);

  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Clearing the music library :( : \n");
  add_song(mlib, "acd", "efg");
  print_letter(mlib, 'e');
  */

  return 0;


}
