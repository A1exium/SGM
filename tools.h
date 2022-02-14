//
// Created by alexium on 11.02.2022.
//

#ifndef SGM__TOOLS_H_
#define SGM__TOOLS_H_

#include "const.h"

typedef struct ListObjectItem_s {
  void *game_object;
  struct ListObject_s *prev;
  struct ListObject_s *next;
} ListObjectItem;

// двусвязный список
typedef struct ListObject_s {
  ListObjectItem *head;
} ListObject;

// Возвращает следущий элемент в списке
extern ListObjectItem *list_object_next(ListObjectItem *item);

// Создает новый список и возвращает его
extern ListObject ListObject_new();

// Удаляет список и все объекты в нем
extern void list_object_drop(ListObject list);

// Добавляет элемент в список
extern void list_object_add(ListObject list, ListObjectItem item);

// Удаляет элемент из списка и возвращает его
extern ListObjectItem *listo_bject_remove(ListObject list, ListObjectItem item);

// Возвращает элемент под индексом index
extern ListObjectItem *list_object_get(ListObject list, int index);

// Удаляет элемент под индексом index и возвращает его
extern ListObjectItem *list_object_pop(ListObject list, int index);

#endif //SGM__TOOLS_H_
