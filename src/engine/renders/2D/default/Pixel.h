//
// Created by alexium on 04.03.2022.
//

#ifndef SGM_SRC_ENGINE_RENDERS_2D_SCREEN_PIXEL_H_
#define SGM_SRC_ENGINE_RENDERS_2D_SCREEN_PIXEL_H_

#define byte unsigned char

struct Pixel_s {
  byte r;
  byte g;
  byte b;
};

struct Pixel_s;
typedef struct Pixel_s Pixel;

extern Pixel Pixel_new(byte r, byte g, byte b);

//extern byte Pixel_get_color()
#define Pixel_get_color(pixel, color) \
  pixel.color

#endif //SGM_SRC_ENGINE_RENDERS_2D_SCREEN_PIXEL_H_
