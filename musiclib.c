#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "musiclist.h"
#include "musiclib.h"

void get_index(char *a) {
	if (a[0]-'a' < 0 || a[0]-'a' > 25) {
		return 26;
	}
	else {
		return a[0]-'a';
	}
}

void add_song(struct song_node *list[], char *n, char *a) {
	int index = get_index(a);
	
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

void print_letter(struct song_node *list[], char l) {
	int index = get_index(a);
	if (index < 26) {
		printf("%c list:\n", 'a' + index);
		print_list(list[i]);
	}
	else {
		printf("Misc list:\n");
		print_list(list[26]);
	}
}
