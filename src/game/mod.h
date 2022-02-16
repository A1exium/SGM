//
// Здесь должно располагаться публичное API
// Т.е Подключать ТОЛЬКО этот файл для операций над объектами откуда-либо еще
//

#ifndef SGM_SRC_GAME_MOD_H_
#define SGM_SRC_GAME_MOD_H_

#include "GameObject.h"
#include "ListGameObject.h"
#include "../const.h"
#include "Area.h"

// Создает игровой объект(GameObject) и помещает его в список class, а также в двумерный массив area;
/*
 * GameObjectType type: Тип игрового объекта
 * int x: координата по х
 * int y: координата по y
 * Area area: двумерный массив указателей на GameObject - Может быть Null.
 * List *class: Список указателей на GameObject - Может быть Null.
 * -> возвращает указатель на созданный объект;
 */
extern GameObject *createGameObject(GameObjectType type, int x, int y, Area area, ListGameObject *group);

// Инициализирует все нужные Структуры и объекты
// Может дополняться
extern void initGame(Area area, List *players, List *nishals);

#endif //SGM_SRC_GAME_MOD_H_
