#include "musiclist.h"

void add_song(struct song_node *list[27], char *n, char *a);
void clear(struct song_node *list[]);
void print_lib(struct song_node *list[]);
void print_letter(struct song_node *list[], char l);
int get_index(char c);
struct song_node *find_song(struct song_node *list[], char *n, char *a);
