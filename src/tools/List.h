//
// Created by alexium on 16.02.2022.
//

#ifndef SGM_SRC_TOOLS_LIST_H_
#define SGM_SRC_TOOLS_LIST_H_

typedef struct ListItem_s {
  void *value;
  struct ListItem_s *prev;
  struct ListItem_s *next;
} ListItem;

// двусвязный список
typedef struct List_s {
  ListItem *head;
} List;

extern ListItem *ListItem_new();

// Возвращает следущий элемент в списке
extern ListItem *list_next(ListItem *item);

// Создает новый список и возвращает его
extern List *List_new();

// Удаляет список и все объекты в нем
extern void list_drop(List *list);

// Добавляет элемент в список
extern void list_add(List *list, void *value);

// Удаляет элемент из списка и возвращает его
extern ListItem *list_remove(ListItem *item);

// Возвращает элемент под индексом index
extern ListItem *list_get(List list, int index);

// Удаляет элемент под индексом index и возвращает его
extern ListItem *list_pop(List list, int index);

#endif //SGM_SRC_TOOLS_LIST_H_