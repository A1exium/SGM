//
// Created by alexium on 04.03.2022.
//

#include "Pixel.h"

Pixel Pixel_new(byte r, byte g, byte b) {
  Pixel pix;
  pix.r = r;
  pix.g = g;
  pix.b = b;
  return pix;
}
