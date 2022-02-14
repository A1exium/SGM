//
// Created by alexium on 11.02.2022.
//
#ifndef SGM__GAME_H_
#define SGM__GAME_H_

#include "const.h"
#include "tools.h"

typedef enum GameObjectType_t {
  None,
  Player,
  Nishal,
} GameObjectType;

typedef struct GameObject_s {
  GameObjectType type;
  int x;
  int y;
} GameObject;

//static GameObject *area[AREA_H][AREA_W];
//static List *players;
//static List *nishals;

// Создает новый объект в координатах
inline GameObject *GameObject_new(GameObjectType type, int x, int y);

// Отчищает объект
inline void gameobject_drop(GameObject *gameobject) {

}

// Двигает объект на дельту по координатам
inline void gameobject_move(GameObject *obj, int dx, int dy);

// "Телепортирует" объект на координаты
inline void gameobject_teleport(GameObject *obj, int x, int y);

// Добавляет игровой объект в список
inline void list_gameobject_add(List list, GameObject obj);

// --------------------
//      Public API
// --------------------
// Здесь размещаются функции, которые вызываются в мейне

// Создает игровой объект(GameObject) и помещает его в список в зависимости от типа type;
extern void createGameObject(GameObjectType area[AREA_H][AREA_W], List *class, GameObjectType type, int x, int y);

// Заполняет объекты в массиве area
extern void initGame(GameObjectType area[AREA_H][AREA_W], List *players, List *nishals);

#endif //SGM__GAME_H_
