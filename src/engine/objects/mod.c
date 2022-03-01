//
// Created by alexium on 14.02.2022.
//

#include "mod.h"
#include "GameObject.h"
#include "Area.h"

// Создает игровой объект(GameObject) и помещает его в список в зависимости от типа type;
GameObject *createGameObject(GameObjectType type, int x, int y, int z, Area area, ListGameObject *class) {
  GameObject *game_object = GameObject_new(type, x, y, z);
  if (area) {
    area[x][y][z] = game_object;
  }
  if (class) {
    listGameObject_add(class, game_object);
  }
  return game_object;
}

void initGame(Area area, List *players, List *nishals) {
  Area_init(area);
  for (int y = 0; y < AREA_MAX_X; y++) {
    for (int x = 0; x < AREA_MAX_Y; x++) {
      createGameObject(Nishal, x, y, 0, area, 0);
    }
  }
  createGameObject(Player, AREA_MAX_X / 2, AREA_MAX_Y / 2, 0, area, 0);
}
