//
// Created by alexium on 14.02.2022.
//

#include "GameObject.h"
#include <stdlib.h>
#include "ListGameObject.h"

/*
 * GameObjectType type - Тип объекта. Все возможные типы находятся в GameObject.h
 *
 * ListGameObject *group - группа(список в текущей реализации), где хранится указатель на ЭТОТ объект.
 * Группы Нужны, чтобы групировать объекты по каким-либо признакам.
 * В будущем может потребоваться хранить один объект в нескольких группах.
 *
 * int x, y - координаты объекта. ДОЛЖНЫ совпадать с теми, где находится объект в AREA.
 *
 * Стуктура может меняться.
 *
 */
struct s_GameObject {
  GameObjectType type;
  ListGameObject *group;
  int x;
  int y;
};

GameObject *GameObject_new(GameObjectType type, int x, int y) {
  GameObject *obj = (GameObject *) malloc(sizeof(GameObject));
  obj->type = type;
  obj->group = 0;
  obj->y = y;
  obj->x = x;
  return obj;
}

GameObjectType gameObject_get_type(GameObject *obj) {
  return obj->type;
}

GameObjectType gameObject_set_type(GameObject *obj, GameObjectType new_type) {
  obj->type = new_type;
}
