//
// Created by alexium on 11.02.2022.
//

#include "console.h"
#include <stdio.h>

void print(Area area) {

  for (int y = 0; y < AREA_H; y++) {
    for (int x = 0; x < AREA_W; x++) {
      switch (gameObject_get_type(area[y][x])) {
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