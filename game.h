//
// Created by alexium on 11.02.2022.
//
#ifndef SGM__GAME_H_
#define SGM__GAME_H_

#include "const.h"


enum Part {
  Player,
  Nishal,
};

struct Object_s{
  enum Part type;
  int x;
  int y;
};

typedef struct Object_s Object;

Object *area[AREA_H][AREA_W];


#endif //SGM__GAME_H_
