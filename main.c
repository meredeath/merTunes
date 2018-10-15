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
  return 0;
}
