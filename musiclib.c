#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "musiclist.h"
#include "musiclib.h"

int get_index(char c) {
	if (c-'a' < 0 || c-'a' > 25) {
		return 26;
	}
	else {
		return c-'a';
	}
}

void add_song(struct song_node *list[], char *n, char *a) {
  int index = get_index(a[0]);
  list[index] = insert_ordered(list[index],n,a);
	
}

void clear(struct song_node *list[]) {
	for(int i = 0; i < 27; i++) {
		list[i] = free_list(list[i]);
	}
}

void print_lib(struct song_node *list[]) {
	printf("Begin Library\n");
	for(int i = 0; i < 26; i++) {
		if (list[i]) {
			printf("%c list:\n", 'a' + i);
			print_list(list[i]);
		}
	}
	if (list[26]) {
			printf("Misc list:\n");
			print_list(list[26]);
		}
	printf("End Library\n");
}

void print_letter(struct song_node *list[], char l) {
	int index = get_index(l);
	if (index < 26) {
		printf("%c list:\n", 'a' + index);
		print_list(list[index]);
	}
	else {
		printf("Misc list:\n");
		print_list(list[26]);
	}
}

void print_artist(struct song_node *list[], char * a){
  int index = get_index(a[0]);
  struct song_node *cur = list[index];
  while(cur){
    if(strcmp(cur->artist, a)==0){
      print_single(cur);
    }
    cur = cur->next;
  }
  printf("This artist does not exist in the queue.\n");
}

struct song_node *find_song(struct song_node *list[], char *n, char *a) {
	int index = get_index(a[0]);
	return find_node(list[index], n, a);
}

struct song_node *find_artist(struct song_node *list[], char *a) {
	int index = get_index(a[0]);
	return first_song_of(list[index], a);
}

