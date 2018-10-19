#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "musiclist.h"

void print_list(struct song_node *first) {
	printf("Begin List\n");
	struct song_node *current = first;
	while(current != NULL) {
		print_single(current);
		current = current->next;
	}
	printf("End List\n");
}

void print_single(struct song_node *first){
  if(first==NULL){
    printf("This list has nothing in it/your value was not found.\n");
    return;
  }
  printf("Song Name: %s\n", first->name);
  printf("Artist Name: %s\n", first->artist);
}

struct song_node * insert_front(struct song_node *first, char * n, char * a) {
	struct song_node *ref = new_node(n,a);
	ref->next = first;
	return ref;
}
struct song_node * free_list(struct song_node *first) {
	if (first == NULL) {
		return NULL;
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
	strncpy(ref->name,n,strlen(n));
	strncpy(ref->artist,a,strlen(a));
	ref->next = NULL;
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

int len(struct song_node *first) {
 	int len = 0;
 	struct song_node * cur = first;
 	while(cur){
    len++;
    cur = cur->next;
  }
  return len;
}

struct song_node * return_rand(struct song_node *first){

  srand(time(NULL));
  int r = rand() % len(first);

  struct song_node *temp = first;
  while(r>0){
    temp = temp->next;
    r--;
  }

  //struct song_node *ans = new_node(temp->name,temp->artist);
  return temp;
}

struct song_node * find_node(struct song_node *first, char *n, char *a){
  struct song_node *temp = new_node(n,a);
  struct song_node *cur = first;
  while(cur){
    if(compare(cur,temp)==0){
      free(temp);
      return cur;
    }
    cur = cur->next;
  }
  free(temp);
  return NULL;
}

struct song_node * first_song_of(struct song_node *first, char *a){
  struct song_node *cur = first;
  while(cur && strcmp(cur->artist,a)<=0){
    if(strcmp(cur->artist,a)==0){
      return cur;
    }
    cur = cur->next;
  }
  printf("%s not found in queue\n",a);
  return NULL;
}

struct song_node * remove_node(struct song_node *first, char *n, char *a) {
	struct song_node *temp = new_node(n,a);
	struct song_node *prev = NULL;
  struct song_node *cur = first;
  while(cur){
    if(compare(cur,temp)==0){
      free(temp);
      if(cur == first) {
      	temp = first->next;
      	free(cur);
      	return temp;
      }
      else {
      	prev->next = cur->next;
      	free(cur);
      	return first;
      }
    }
    prev = cur;
    cur = cur->next;
  }
  free(temp);
  return first;
}
