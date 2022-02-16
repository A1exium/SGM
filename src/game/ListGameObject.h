//
// Здесь список (List из tools), но для работы с GameObject *, а не с void *
//

#ifndef SGM_SRC_GAME_LISTGAMEOBJECT_H_
#define SGM_SRC_GAME_LISTGAMEOBJECT_H_

#include "../tools/List.h"
#include "GameObject.h"

typedef List ListGameObject;

// Создает новый объект типа List и возвращает его
ListGameObject *ListGameObject_new();

// Отчищает память списка.
// Отчищает память всех его элементов, если их нет в area???
// TODO
void listGameObject_free(ListGameObject *list);

// Добавляет GameObject * в список
void listGameObject_add(ListGameObject *list, GameObject *game_object);

// Удаляет элемент из коллекции и возвращает его
// TODO
GameObject *listGameObject_remove(ListGameObject *list, GameObject *game_object);

#endif //SGM_SRC_GAME_LISTGAMEOBJECT_H_
