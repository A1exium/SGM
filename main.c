//
// Created by alexium on 11.02.2022.
//
#include "visual.h"
#include <stdio.h>
#include "game.h"

int main() {
  init_game(area, players, nishals);
  while (1) {
    getchar();

    print(area);
  }

}