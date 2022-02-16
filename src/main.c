//
// Created by alexium on 11.02.2022.
//
#include "output/mod.h"
#include "game/mod.h"

int main() {
  Area area;
  area_init(area);
  ListGameObject *players = ListGameObject_new();
  ListGameObject *nishals = ListGameObject_new();
  initGame(area, players, nishals);
  print(area);
  listGameObject_free(players);
  listGameObject_free(nishals);
}