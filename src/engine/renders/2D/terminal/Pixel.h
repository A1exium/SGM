//
// Created by alexium on 07.03.2022.
//

#ifndef SGM_SRC_ENGINE_RENDERS_2D_TERMINAL_PIXEL_H_
#define SGM_SRC_ENGINE_RENDERS_2D_TERMINAL_PIXEL_H_

#include "../default/Pixel.h"

struct Pixel_s {
  char symbol;
  char *color;
  char *bg_color;
};

extern Pixel Pixel_from(char sym, enum Colors color, enum Colors bg_color);

#endif //SGM_SRC_ENGINE_RENDERS_2D_TERMINAL_PIXEL_H_
