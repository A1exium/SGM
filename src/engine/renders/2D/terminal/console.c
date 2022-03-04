//
// Created by alexium on 11.02.2022.
//

#include "console.h"
#include <stdio.h>

void print(Picture pic, int height, int width) {

  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      putchar(Picture_get_pixel(pic, x, y).r);
    }
    putchar('\n');
  }
}