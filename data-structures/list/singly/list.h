#ifndef LIST_H
#define LIST_H

#include <stdint.h>
#include <stddef.h>

typedef struct List List;
typedef struct Node Node;

typedef void (*PrintFn)(const void *data);

List  *new_list(size_t data_size);
void  *get_item(List *list, int index);
void   insert_end(List *list, void *data);
void   print_list(List *list, PrintFn print_fn);
void   delete_list(List *list);
int    is_empty(List *list);
int    list_length(List *list);

#endif  // LIST_H

