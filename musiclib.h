#include "musiclist.h"

void add_song(struct song_node *list[27], char *n, char *a);
void delete_song(struct song_node *list[27], char *n, char *a);
void clear(struct song_node *list[]);
void print_lib(struct song_node *list[]);
void print_letter(struct song_node *list[], char l);
void print_artist(struct song_node *list[], char *a);
void shuffle(struct song_node *list[], int n);
int get_index(char c);
struct song_node *find_song(struct song_node *list[], char *n, char *a);
struct song_node *find_artist(struct song_node *list[], char *a);
struct song_node * pick_ran(struct song_node *list[]);

