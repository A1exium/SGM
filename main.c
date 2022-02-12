//
// Created by alexium on 11.02.2022.
//
#include "visual.h"
#include <stdio.h>
#include "game.h"

int main() {
  render_init();
  Object area[AREA_H][AREA_W];
  area_create(area);
  while (1) {
    getchar();

    print(area);
  }

}