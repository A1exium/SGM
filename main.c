//
// Created by alexium on 11.02.2022.
//
#include "visual.h"
#include "game.h"
#include <curses.h>

int main() {
  render_init();
  init_game(area, players, nishals);
  chtype w = 0;

  while (w != 'q') {
    print(area);
    w = getch();
    refresh();
  }
  render_destroy();
}