//
// Created by alexium on 02.03.2022.
//

#include "View.h"
#include "../../../geometry/Position.h"
#include <stdlib.h>

struct View_s {
  Area *area;
  Position pos;
  int width;
  int height;
};

View *View_new(Area *area, int x, int y, int width, int height) {
  View *view = (View *)malloc(sizeof(View));
  view->pos = Position_new(x, y, 0);
  view->height = height;
  view->area = area;
  view->width = width;
  return view;
}
