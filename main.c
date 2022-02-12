//
// Created by alexium on 11.02.2022.
//
#include "visual.h"
#include "game.h"
#include <curses.h>
#include <unistd.h>

int main() {
  render_init();
  init_game(area, players, nishals);
  chtype w = 0;

  while (w != 'q') {
    w = getch();
    print(area);

    sleep(1);
  }
  render_destroy();
}