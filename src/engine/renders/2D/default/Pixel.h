//
// Created by alexium on 04.03.2022.
//

#ifndef SGM_SRC_ENGINE_RENDERS_2D_SCREEN_PIXEL_H_
#define SGM_SRC_ENGINE_RENDERS_2D_SCREEN_PIXEL_H_

#define byte unsigned char

#include "colors.h"

struct Pixel_s;
typedef struct Pixel_s Pixel;

extern Pixel Pixel_new();

extern Pixel Pixel_from_color(enum Colors color);

extern int Pixel_is_empty(Pixel *pix);

#endif //SGM_SRC_ENGINE_RENDERS_2D_SCREEN_PIXEL_H_
