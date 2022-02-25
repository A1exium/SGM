/**
 * Здесь структура двусвязанного списка.
 */

#ifndef SGM_SRC_TOOLS_LIST_H_
#define SGM_SRC_TOOLS_LIST_H_

struct ListItem_s;
typedef struct ListItem_s ListItem;

/** двусвязный список
 */
typedef struct List_s List;

/**
 * Возвращает новый экземпляр списка
 */
ListItem *ListItem_new();

/**
 * Возвращает следущий элемент в списке
 */
ListItem *list_next(ListItem *item);

/**
 * Создает новый список и возвращает его
 */
List *List_new();

/**
 * Удаляет список и все объекты в нем
 */
void list_free(List *list);

/**
 * Добавляет ListItem в список
 */
void list_add_item(List *list, ListItem *item);

/**
 * Добавляет элемент в список
 */
void list_add(List *list, void *value);

// TODO
/**
 * Удаляет элемент из списка и возвращает его
 */
ListItem *list_remove(ListItem *item);

// TODO
/**
 * Возвращает элемент под индексом index
 */
ListItem *list_get(List list, int index);

// TODO
/**
 * Удаляет элемент под индексом index и возвращает его
 */
ListItem *list_pop(List list, int index);

#endif //SGM_SRC_TOOLS_LIST_H_
