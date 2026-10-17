#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

struct Node {
  Node  *next;
  void  *data;
};

struct List {
  Node  *head;
  Node  *tail;
  int    length;
  size_t data_size;
};

List *new_list(size_t data_size) {
  List *list = (List *) malloc(sizeof(List));

  if (list == NULL)
    return NULL;

  list->head      = NULL;
  list->tail      = NULL;
  list->length    = 0;
  list->data_size = data_size;

  return list;
}

void print_list(List *list, PrintFn print_fn) {
  if (is_empty(list) || list == NULL || print_fn == NULL)
    return;

  Node *current = list->head;

  printf("[");
  while (current != NULL) {
    print_fn(current->data);

    if (current->next != NULL)
      printf(", ");

    current = current->next;
  }

  printf("]\n");
}

void *get_item(List *list, int index) {
  if (is_empty(list) || index >= list->length) 
    return NULL;

  Node *pointer = list->head;

  int i = 0;
  while (pointer != NULL) {
    if (i++ == index) 
      return pointer->data;
    pointer = pointer->next;
  }

  return NULL;
}

void delete_list(List *list) {
  Node *pointer = list->head;

  Node *next;
  while (pointer != NULL) {
    next = pointer->next;
    free(pointer->data);
    free(pointer);
    pointer = next;
  }

  free(list);
}

void insert_end(List *list, void *data) {
  Node *new = (Node *) malloc(sizeof(Node));

  if (new == NULL)
    return;

  new->data = malloc(list->data_size);

  if (new->data == NULL) {
    free(new);
    return;
  }

  memcpy(new->data, data, list->data_size);

  new->next = NULL;

  // Insert to an empty list.
  if (is_empty(list)) {
    list->head   = new;
    list->tail   = new;
    list->length = 1;
  }
  // Insert to a non-empty list.
  else {
    list->tail->next = new;
    list->tail       = new;
    list->length     = list->length + 1;
  }
}

int list_length(List *list) {
  return list->length;
} 

int is_empty(List *list) {
  return list->length == 0;
}

