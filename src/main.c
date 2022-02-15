//
// Created by alexium on 11.02.2022.
//
#include "output/mod.h"
#include "game/mod.h"

int main() {
//  init_game(area, players, nishals);
  GameObjectType area[AREA_H][AREA_W];
  List *players = List_new();
  List *nishals = List_new();
  initGame(area, players, nishals);
  print(area);
}