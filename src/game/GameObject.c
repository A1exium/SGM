//
// Created by alexium on 14.02.2022.
//

#include "GameObject.h"
#include <stdlib.h>



struct s_GameObject {
  GameObjectType type;
  int x;
  int y;
};

GameObject *GameObject_new(GameObjectType type, int x, int y) {
  GameObject *obj = (GameObject *) malloc(sizeof(GameObject));
  obj->type = type;
  obj->y = y;
  obj->x = x;
  return obj;
}
