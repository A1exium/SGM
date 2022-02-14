//
// Created by alexium on 11.02.2022.
//

#include "game.h"
#include <stdlib.h>

GameObject *GameObject_new(GameObjectType type, int x, int y) {
  GameObject *obj = (GameObject *)malloc(sizeof(GameObject));
  obj->type = type;
  obj->y = y;
  obj->x = x;
  return obj;
}

// Создает игровой объект(GameObject) и помещает его в список в зависимости от типа type;
void createGameObject(GameObjectType area[AREA_H][AREA_W], List *class, GameObjectType type, int x, int y) {
  GameObject *game_object = GameObject_new(type, x, y);
  area[y][x] = type;
  if (class) {
    list_add(class, game_object);
  }
}

void initGame(GameObjectType area[AREA_H][AREA_W], List *players, List *nishals) {
  for (int y = 0; y < AREA_H; y++) {
    for (int x = 0; x < AREA_W; x++) {
      createGameObject(area, nishals, Nishal, x, y);
    }
  }
  createGameObject(area, players, Player, AREA_W / 2, AREA_H / 2);
}