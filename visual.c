//
// Created by alexium on 11.02.2022.
//

#include "visual.h"
#include <stdio.h>

void print() {

  for (int y = 0; y < AREA_H; y++) {
    for (int x = 0; x < AREA_W; x++) {
      enum Part obj_type = area[y][x].type;
      switch (obj_type) {
        case Player:putchar('#');
          break;
        case Nishal:putchar('*');
          break;
        default:putchar(' ');
          break;
      }
    }
    putchar('\n');
  }
}