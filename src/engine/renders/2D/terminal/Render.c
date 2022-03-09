//
// Created by alexium on 04.03.2022.
//

#include "../base/Render.h"
#include <stdlib.h>
#include "../../../objects/GameObject.h"
#include "../default/Texture.h"

struct Render_s {
  View *view;
  int width;
  int height;
};

Render *Render_new(View *view, int width, int height) {
  Render *render = (Render *) malloc(sizeof(Render));
  render->height = height;
  render->width = width;
  render->view = view;
  return render;
}

const int TEXTURE_RATIO = 3;

#include <stdio.h>
#include "Pixel.h"

Picture Render_render(Render *render) {

  Texture *PLAYER_TEXTURE = Texture_load(fopen("../assets/player.nsd", "r"));
  Texture *NISHAL_TEXTURE = Texture_load(fopen("../assets/nishal.nsd", "r"));
  Texture *TILE_TEXTURE = Texture_load(fopen("../assets/tile.nsd", "r"));
  Texture *NONE_TEXTURE = Texture_load(fopen("../assets/none.nsd", "r"));

  Picture pic = Picture_new(render->width, render->height);
  Position view_pos = View_get_pos(render->view);
  for (int x = view_pos.x; x < View_get_width(render->view); x++) {
    for (int y = view_pos.y; y < View_get_height(render->view); y++) {
      for (int z = 0; z < AREA_MAX_Z; z++) {
        Texture *cur_texture;
        GameObject *cur_obj = View_get_GameObject(render->view, x, y, z);
        if (cur_obj) {
          switch (gameObject_get_type(cur_obj)) {
            case Tile: {
              cur_texture = TILE_TEXTURE;
              break;
            }
            default: {
              cur_texture = NONE_TEXTURE;
              break;
            }
            case Player: {
              cur_texture = PLAYER_TEXTURE;
              break;
            }
            case Nishal: {
              cur_texture = NISHAL_TEXTURE;
              break;
            }
          }
          for (int tx = 0; tx < TEXTURE_RATIO; tx++) {
            for (int ty = 0; ty < TEXTURE_RATIO; ty++) {
              Pixel cur_pixel = Texture_get_pixel(cur_texture, tx, ty);
//              if (!Pixel_is_empty(&cur_pixel))
              if (cur_pixel.symbol != ' ')
                Picture_set_pixel(pic, x * TEXTURE_RATIO + tx, y * TEXTURE_RATIO + ty, cur_pixel);
            }
          }
        }
      }
    }
  }
  return pic;
}
