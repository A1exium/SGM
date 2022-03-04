//
// Created by alexium on 02.03.2022.
//

#include "Screen.h"
#include <stdlib.h>

struct Screen_s {
  int width;
  int height;
  View *view;
};

Screen *Screen_new(int width, int height, View *view) {
  Screen *screen = (Screen *)malloc(sizeof(Screen));
  screen->width = width;
  screen->height = height;
  screen->view = view;
  return screen;
}


