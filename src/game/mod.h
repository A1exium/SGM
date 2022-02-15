//
// Здесь должно располагаться публичное API
// Т.е Подключать ТОЛЬКО этот файл для операций над объектами откуда-либо еще
//

#ifndef SGM_SRC_GAME_MOD_H_
#define SGM_SRC_GAME_MOD_H_

#include "GameObject.h"
#include "../tools/List.h"
#include "../const.h"

// Создает игровой объект(GameObject) и помещает его в список в зависимости от типа type;
extern void createGameObject(GameObjectType area[AREA_H][AREA_W], List *class, GameObjectType type, int x, int y);

// Заполняет объекты в массиве area
extern void initGame(GameObjectType area[AREA_H][AREA_W], List *players, List *nishals);

#endif //SGM_SRC_GAME_MOD_H_
