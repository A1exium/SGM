//
// Created by alexium on 11.02.2022.
//
#include "visual.h"
#include "game.h"
#include <curses.h>
#include <unistd.h>

int main() {
  render_init();
  Object area[AREA_H][AREA_W];
  area_create(area);
  chtype w = 0;

  while (w != 'q') {
    w = getch();
    print(area);

    sleep(1);
  }
  render_destroy();
}