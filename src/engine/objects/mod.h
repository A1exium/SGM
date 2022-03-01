///
/// Здесь должно располагаться публичное API
/// Т.е Подключать ТОЛЬКО этот файл для операций над объектами откуда-либо еще
///

#ifndef SGM_SRC_GAME_MOD_H_
#define SGM_SRC_GAME_MOD_H_

#include "GameObject.h"
#include "ListGameObject.h"
#include "../../globals/const.h"
#include "Area.h"

/**
 * Создает игровой объект(GameObject) и помещает его в список class, а также в двумерный массив area;
 * @param type Тип игрового объекта
 * @param x координата по х
 * @param y координата по y
 * @param area двумерный массив указателей на GameObject - Может быть Null(0).
 * @param class Список указателей на GameObject - Может быть Null(0).
 * @return возвращает указатель на созданный объект;
 */
extern GameObject *createGameObject(GameObjectType type, int x, int y, int z, Area area, ListGameObject *group);

/**
 * Инициализирует все нужные Структуры и объекты
 * Может дополняться
 * @param area Инициализаруемое поле
 * @param players Список игроков
 * @param nishals Список ботов
 */
extern void initGame(Area area, List *players, List *nishals);

#endif //SGM_SRC_GAME_MOD_H_
