#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "musiclist.h"

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
  

  return 0;
}
