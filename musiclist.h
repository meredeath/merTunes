#ifndef LINK_LIST_H
#define LINK_LIST_H

//IGNORE
/*
struct music_list{
  song_node *first;
  song_node *last;
  int length;
}
*/

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

void print_list(struct song_node *first);
void print_single(struct song_node *first);
struct song_node * insert_front(struct song_node *first, char * n, char * a);
struct song_node * free_list(struct song_node *first);
int compare(struct song_node *a, struct song_node *b);
struct song_node * new_node(char * n, char * a);
struct song_node * insert_ordered(struct song_node *first, char * n, char * a);
struct song_node * return_rand(struct song_node *first);
struct song_node * find_node(struct song_node *first, char *n, char *a);
struct song_node * first_song_of(struct song_node *first, char *a);


#endif
