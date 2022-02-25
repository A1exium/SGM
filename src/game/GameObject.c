//
// Created by alexium on 14.02.2022.
//

#include "GameObject.h"
#include <stdlib.h>
#include "ListGameObject.h"

struct s_GameObject {
  GameObjectType type;
  ListGameObject *group;
  void *properties;
  int x;
  int y;
  int z;
};

GameObject *GameObject_new(GameObjectType type, int x, int y, int z) {
  GameObject *obj = (GameObject *) malloc(sizeof(GameObject));
  obj->type = type;
  obj->group = 0;
  obj->y = y;
  obj->x = x;
  obj->z = z;
  return obj;
}

GameObjectType gameObject_get_type(GameObject *obj) {
  return obj->type;
}

GameObjectType gameObject_set_type(GameObject *obj, GameObjectType new_type) {
  obj->type = new_type;
}
