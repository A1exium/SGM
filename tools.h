//
// Created by alexium on 11.02.2022.
//

#ifndef SGM__TOOLS_H_
#define SGM__TOOLS_H_

#include "game.h"

typedef struct ListObject_s {
  Object item;
  struct ListObject_s *prev;
  struct ListObject_s *next;
} ListObject;

#endif //SGM__TOOLS_H_
