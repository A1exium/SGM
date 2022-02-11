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

Object area[AREA_H][AREA_W];

// Заполняет объекты в массиве
void CreateArea(Object area[AREA_H][AREA_W]);

//
void MoveObject(Object *)

#endif //SGM__GAME_H_
