//
// Created by alexium on 11.02.2022.
//
#ifndef SGM__GAME_H_
#define SGM__GAME_H_

#include "const.h"
#include "tools.h"

typedef enum GameObjectProjection_t {
  Player,
  Nishal,
  None,
} GameObjectProjection;

typedef struct GameObject_s {
  int id;
  int x;
  int y;
} GameObject;

// Заполняет объекты в массиве
extern void init_game(GameObjectProjection area[AREA_H][AREA_W], ListObject players, ListObject nishals);

// Двигает объект на дельту по координатам
extern void object_move(GameObject *obj, int dx, int dy);

// "Телепортирует" объект на координаты
extern void object_teleport(GameObject *obj, int x, int y);

static GameObjectProjection area[AREA_H][AREA_W];
static ListObject players;
static ListObject nishals;

#endif //SGM__GAME_H_
