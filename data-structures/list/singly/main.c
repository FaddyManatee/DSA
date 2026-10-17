#include <stdio.h>
#include <stdlib.h>

#include "list.h"

typedef struct {
  char *name;
  int   id;
} User;

void print_int(const void *data) {
  printf("%d", *(const int *)data);
}

void print_user(const void *data) {
  const User *user = data;
  printf("%s (%d)", user->name, user->id);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <number-list-length>\n", argv[0]);
    return 1;
  }

  int limit = atoi(argv[1]);

  if (limit <= 0) {
    printf("<number-list-length> must be a positive integer!\n");
    return 1;
  }

  // Create a list of numbers.
  List *int_list = new_list(sizeof(int));

  // Create a list of users.
  List *user_list = new_list(sizeof(User));

  if (int_list == NULL || user_list == NULL) {
    printf("Memory allocation error!\n");
    return 1;
  }

  // Populate the number list.
  int i;
  for (i = 1; i <= limit ; ++i)
    insert_end(int_list, &i);

  // Populate the user list.
  User user_1 = { "Jeremy", 14965837 };
  User user_2 = { "Lucas", 76249854 };
  User user_3 = { "Claire", 54218421 };

  insert_end(user_list, &user_1);
  insert_end(user_list, &user_2);
  insert_end(user_list, &user_3);

  // Print the lists and their lengths.
  print_list(int_list, print_int);
  printf("The number list has %d elements!\n\n", list_length(int_list));

  print_list(user_list, print_user);
  printf("The user list has %d elements!\n", list_length(int_list));

  // Delete the lists.
  delete_list(int_list);
  delete_list(user_list);

  return 0;
}

