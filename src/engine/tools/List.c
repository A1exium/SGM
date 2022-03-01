//
// Created by alexium on 16.02.2022.
//

#include "List.h"
#include <stdlib.h>

struct ListItem_s {
  void *value;
  ListItem *prev;
  ListItem *next;
};

struct List_s {
  ListItem *head;
};

List *List_new() {
  return (List *) malloc(sizeof(List));
}

void listItem_free(ListItem *list_item) {
  if (list_item->next) listItem_free(list_item->next);
  free(list_item);
}

void list_free(List *list) {
  if (list->head) listItem_free(list->head);
  free(list);
}

ListItem *ListItem_new(void *value) {
  ListItem *item = (ListItem *)malloc(sizeof(ListItem));
  item->value = value;
  return item;
}

void list_add_item(List *list, ListItem *item) {
  if (list->head) {
    ListItem *insertion_item = list->head;
    while (insertion_item->next) {
      insertion_item = (ListItem *) insertion_item->next;
    }
    item->prev = insertion_item;
    insertion_item->next = item;
  } else {
    list->head = item;
  }
}

void list_add(List *list, void *value) {
  list_add_item(list, ListItem_new(value));
}

ListItem *list_next(ListItem *item) {
  return item->next;
}
