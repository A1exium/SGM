//
// Created by alexium on 14.02.2022.
//

#include "Area.h"

void area_init(Area area) {
  for (int y = 0; y < AREA_H; y++)
    for (int x = 0; x < AREA_W; x++)
      area[y][x] = 0;
}
