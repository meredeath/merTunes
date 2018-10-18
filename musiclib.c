#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "musiclist.h"
#include "musiclib.h"

void add_song(struct song_node *list[], char *n, char *a) {
	int index;
	if (a[0]-'a' < 0 || a[0]-'a' > 25) {
		index = 26;
	}
	else {
		index = a[0]-'a';
	}
	if (list[index] == NULL) {
		list[index] = new_node(n,a);
	}
	else {
		list[index] = insert_ordered(list[index],n,a);
	}
}

void clear(struct song_node *list[]) {
	for(int i = 0; i < 27; i++) {
		list[i] = free_list(list[i]);
	}
}

void print_lib(struct song_node *list[]) {
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
}
