//
// Created by alexium on 11.02.2022.
//
#include "./engine/renders/terminal/mod.h"
#include "engine/objects/mod.h"


// ADMIN LOH
// Second dev tozhe loh.

int main() {
  Area area;
  ListGameObject *players = ListGameObject_new();
  ListGameObject *nishals = ListGameObject_new();
  initGame(area, players, nishals);
  print(area);
  listGameObject_free(players);
  listGameObject_free(nishals);
}