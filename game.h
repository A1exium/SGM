//
// Created by alexium on 11.02.2022.
//
#ifndef SGM__GAME_H_
#define SGM__GAME_H_

#include "const.h"

enum Part {
  Player,
  Nishal,
  None,
};

typedef struct Object_s{
  enum Part type;
} Object;


// Заполняет объекты в массиве
extern void area_create(Object area[AREA_H][AREA_W]);

// Двигает объект на дельту по координатам
extern void object_move(Object *obj, int dx, int dy);

extern void object_teleport(Object *obj, int x, int y);

#endif //SGM__GAME_H_
