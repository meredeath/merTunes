#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musiclist.h"

void print_list(struct song_node *first) {
	printf("Begin List\n");
	struct song_node *current = first;
	while(current != NULL) {
		printf("Song Name: %s\n", current->name);
		printf("Artist Name: %s\n", current->artist);
		current = current->next;
	}
	printf("End List\n");
}
struct song_node * insert_front(struct song_node *first, char * n, char * a) {
	struct song_node *ref = new_node(n,a);
	ref->next = first;
	return ref;
}
struct song_node * free_list(struct song_node *first) {
	if (first->next == NULL) {
		free(first);
	}
	else {
		free_list(first->next);
		free(first);
	}
	return NULL;
}
int compare(struct song_node *a, struct song_node *b) {
	if (strcmp(a->artist,b->artist)==0) {
		return strcmp(a->name,b->name);
	}
	return strcmp(a->artist,b->artist);
}
struct song_node * new_node(char * n, char * a) {
	struct song_node *ref = malloc(sizeof(struct song_node));
	strncpy(ref->name,n,100);
	strncpy(ref->artist,a,100);
	return ref;
}
struct song_node * insert_ordered(struct song_node *first, char * n, char * a) {
	struct song_node *ref = new_node(n,a);
	if (first == NULL) {
		return ref;
	}
	if (compare(ref,first) <= 0) {
		ref->next = first;
		return ref;
	}
	struct song_node *prev = first;
	struct song_node *cur = prev->next;
	while (cur != NULL) {
		if (compare(ref,cur) <= 0) {
			ref->next = cur;
			prev->next = ref;
			return first;
		}
		prev = cur;
		cur = cur->next;
	}
	prev->next = ref;
	return first;
}


