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
