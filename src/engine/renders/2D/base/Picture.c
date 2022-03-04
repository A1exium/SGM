//
// Created by alexium on 04.03.2022.
//

#include "Picture.h"
#include <stdlib.h>

Picture Picture_new(int width, int height) {
  Pixel **indexes = (Pixel **)malloc(sizeof(Pixel *) * width);
  for (int i = 0; i < width; i++) {
    indexes[i] = (Pixel *)malloc(sizeof(Pixel) * height);
    for (int j = 0; j < height; j++) {
      indexes[i][j].r = ' ';
      indexes[i][j].b = ' ';
      indexes[i][j].g = ' ';
    }
  }
  return indexes;
}

Pixel Picture_get_pixel(Picture picture, int x, int y) {
  return picture[x][y];
}

Pixel *Picture_get_pixel_mut(Picture picture, int x, int y) {
  return &picture[x][y];
}
