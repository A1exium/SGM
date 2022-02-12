//
// Created by alexium on 11.02.2022.
//
#ifndef SGM__GAME_H_
#define SGM__GAME_H_

#include "const.h"

typedef enum Projection_t {
  Player,
  Nishal,
  None,
} Projection;

typedef struct Object_s {
  int id;
  int x;
  int y;
} Object;

// Заполняет объекты в массиве
extern void init_game(Projection area[AREA_H][AREA_W], Object players[MAX_PLAYERS], Object nishals[MAX_NISHALS]);

// Двигает объект на дельту по координатам
extern void object_move(Object *obj, int dx, int dy);

extern void object_teleport(Object *obj, int x, int y);

static Projection area[AREA_H][AREA_W];
static Object players[MAX_PLAYERS];
static Object nishals[MAX_NISHALS];

#endif //SGM__GAME_H_
