//
// Created by alexium on 11.02.2022.
//
#include "./engine/renders/2D/terminal/console.h"
#include "engine/objects/mod.h"
#include "engine/renders/2D/base/View.h"
#include "engine/renders/2D/base/Render.h"

// ADMIN LOH
// Second dev tozhe loh.

int main() {
  Area area;
  ListGameObject *players = ListGameObject_new();
  ListGameObject *nishals = ListGameObject_new();
  initGame(area, players, nishals);
  View *global = View_new(&area, 0, 0, AREA_MAX_X, AREA_MAX_Y);
  Render *render = Render_new(global, AREA_MAX_X * 3, AREA_MAX_Y * 3);
  print(Render_render(render), AREA_MAX_Y * 3, AREA_MAX_X * 3);
  listGameObject_free(players);
  listGameObject_free(nishals);
}