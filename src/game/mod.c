//
// Created by alexium on 14.02.2022.
//

#include "mod.h"
#include "GameObject.h"

// Создает игровой объект(GameObject) и помещает его в список в зависимости от типа type;
GameObject *createGameObject(GameObjectType type, int x, int y, Area area, ListGameObject *class) {
  GameObject *game_object = GameObject_new(type, x, y);
  if (area) {
    area[y][x] = game_object;
  }
  if (class) {
    listGameObject_add(class, game_object);
  }
  return game_object;
}

void initGame(Area area, List *players, List *nishals) {
  for (int y = 0; y < AREA_H; y++) {
    for (int x = 0; x < AREA_W; x++) {
      createGameObject(Nishal, x, y, area, 0);
    }
  }
  createGameObject(Player, AREA_W / 2, AREA_H / 2, area, 0);
}
