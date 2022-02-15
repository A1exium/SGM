//
// Created by alexium on 16.02.2022.
//

#include "List.h"
#include <stdlib.h>

List *List_new() {
  return (List *) malloc(sizeof(List));
}

ListItem *ListItem_new(void *value) {
  ListItem *item = (ListItem *)malloc(sizeof(ListItem));
  item->value = value;
  return item;
}

void list_add(List *list, void *value) {
  ListItem *item = ListItem_new(value);
  if (list->head) {
    ListItem *insertion_item = list->head;
    while (insertion_item->next) {
      insertion_item = (ListItem *) insertion_item->next;
    }
    item->prev = (struct ListItem_s *) (struct List_s *) insertion_item;
    insertion_item->next = (struct ListItem_s *) (struct List_s *) item;
  } else {
    list->head = item;
  }
}

ListItem *list_next(ListItem *item) {
  return (ListItem *) item->next;
}
