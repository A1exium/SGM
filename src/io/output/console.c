//
// Created by alexium on 11.02.2022.
//

#include "console.h"
#include <stdio.h>

void print(Area area) {

  for (int x = 0; x < AREA_MAX_X; x++) {
    for (int y = 0; y < AREA_MAX_Y; y++) {
//      for (int z = 0; z < AREA_MAX_Z; z++) {
        if (area[x][y][0]) {
          switch (gameObject_get_type(area[x][y][0])) {
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
//    }
  }
}