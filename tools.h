//
// Created by alexium on 11.02.2022.
//

#ifndef SGM__TOOLS_H_
#define SGM__TOOLS_H_

#include "const.h"

typedef struct ListItem_s {
  void *game_object;
  struct List_s *prev;
  struct List_s *next;
} ListItem;

// двусвязный список
typedef struct List_s {
  ListItem *head;
} List;

// Возвращает следущий элемент в списке
extern ListItem *list_next(ListItem *item);

// Создает новый список и возвращает его
extern List List_new();

// Удаляет список и все объекты в нем
extern void list_drop(List list);

// Добавляет элемент в список
extern void list_add(List list, ListItem item);

// Удаляет элемент из списка и возвращает его
extern ListItem *list_remove(ListItem *item);

// Возвращает элемент под индексом index
extern ListItem *list_get(List list, int index);

// Удаляет элемент под индексом index и возвращает его
extern ListItem *list_pop(List list, int index);

#endif //SGM__TOOLS_H_
