#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "musiclist.h"

int main(){
  struct song_node * n0 = malloc(sizeof(struct song_node));
  char c0[100] = "Star Spangled Banner";
  strncpy(n0->name,(char *)&"Star",100);
  char a0[100] = "Francis Scott Key";
  strncpy(n0->artist,a0,100);
  print_list(n0);

  n0 = insert_front(n0,"Never Gonna Give You Up","Rick Astley");
  print_list(n0);
  struct song_node * n1 = malloc(sizeof(struct song_node));
  strncpy(n1->name,(char *)&"Star",100);
  strncpy(n1->artist,(char *)&"Rick Astley",100);
  printf("%d\n", compare(n0,n1));
  printf("%d\n", compare(n0->next,n1));

  return 0;
}
