//
// Created by alexium on 11.03.2022.
//

#include "engine.h"
#include "../globals/const.h"

enum GameObjectType_t {
  None,
  Tile,
  Player,
  Nishal,
};

void move_board(EventCallbackArgs args) {
  List left = 0;
  List right = 0;
  int *rx = 0, *lx = 0;
  EventCallbackArgs_unpack(args, &left, &right, &rx, &lx);
  Event t_ev;
  t_ev.type = Keyboard;
  if (rx) {
    if (*rx == -1)
      t_ev.key = 'k';
    else
      t_ev.key = 'm';
    int i = 0;
    foreach(GameObject ns = 0, ns, right) {
      if(i == 0 && (gameObject_get_pos(ns).y + *rx == AREA_MAX_Y || gameObject_get_pos(ns).y + *rx == 1))
        break;
      gameObject_move(ns, 0, *rx, 0);
      i++;
    }
  }
  else if (lx) {
    if (*lx == -1)
      t_ev.key = 'a';
    else
      t_ev.key = 'z';
    int i = 0;
    foreach(GameObject ns = 0, ns, left) {
      if(i == 0 && (gameObject_get_pos(ns).y + *lx + 2 == AREA_MAX_Y || gameObject_get_pos(ns).y + *lx == -1))
        break;
      gameObject_move(ns, 0, *lx, 0);
      i++;
    }
  }

//  if (send_event) {
//    send_event(t_ev);
//  }
}

TextureStorage LoadTextures(Render render) {
  TextureStorage storage = TextureStorage_new(4);
  textureStorage_insert(storage, Player, Texture_load(render, get_asset_path("player")));
  textureStorage_insert(storage, Nishal, Texture_load(render, get_asset_path("nishal")));
  textureStorage_insert(storage, Tile, Texture_load(render, get_asset_path("tile")));
  textureStorage_insert(storage, None, Texture_load(render, get_asset_path("none")));
  return storage;
}

void initGame(List players, List nishals_left, List nishals_right, Area area) {
  for (int x = 0; x < AREA_MAX_X; x++) {
    for (int y = 0; y < AREA_MAX_Y; y++) {
      createGameObject(area, Tile, x, y, 0, 0);
//      if ((y == 0 || y == AREA_MAX_Y - 1) && x % 2 == 0 || (x == 0 || x == AREA_MAX_X - 1) && y % 2 == 0) {
//        createGameObject(Nishal, x, y, 1, area, nishals);
//      }
    }
  }
  createGameObject(area, Nishal, 1, 0, 1, nishals_left);
  createGameObject(area, Nishal, 2, 1, 1, nishals_left);
  createGameObject(area, Nishal, 1, 2, 1, nishals_left);
  createGameObject(area, Nishal, AREA_MAX_X - 2, AREA_MAX_Y - 1, 1, nishals_right);
  createGameObject(area, Nishal, AREA_MAX_X - 3, AREA_MAX_Y - 2, 1, nishals_right);
  createGameObject(area, Nishal, AREA_MAX_X - 2, AREA_MAX_Y - 3, 1, nishals_right);
  createGameObject(area,Player, AREA_MAX_X / 2, AREA_MAX_Y / 2, 2,  players);
}

void movePlayer(EventCallbackArgs _args) {
//  int *dx, *dy;
  static int dx = 1, dy = 1;
  GameObject player;
  Area area;
  EventCallbackArgs_unpack(_args, &area, &player);

  Position player_pos = gameObject_get_pos(player);
  int cx = player_pos.x, cy = player_pos.y;
  if (cx >= AREA_MAX_X - 1) {
    dx = -1;
  } else if (cx <= 0) {
    dx = 1;
  }
  if (cy >= AREA_MAX_Y - 1) {
    dy = -1;
  } else if (cy <= 0) {
    dy = 1;
  }
  if (area_get(area, cx + dx, cy + dy, 1) != 0 || area_get(area, cx + dx, cy, 1)) {
    if (cx > AREA_MAX_X / 2)
      dx = -1;
    else
      dx = 1;
  }
  gameObject_move(player, dx, dy, 0);
}

const EventCallbackArgs NO_ARGS = {
    .length = 0,
    .storage = 0,
};

Render GLOBAL_RENDER;

#include <stdlib.h>

void send_t(EventCallbackArgs args) {
  Event t_ev;
  t_ev.key = 'z';
  t_ev.type = Keyboard;
  send_event(t_ev);
}


void start_game() {


  initCurrentRender();

  Area area = Area_new(AREA_MAX_X, AREA_MAX_Y, AREA_MAX_Z);
  List players = List_new();
  List nishal_left = List_new();
  List nishal_right = List_new();
  initGame(players, nishal_left, nishal_right, area);
  View global_view = View_new(area, 0, 0, AREA_MAX_X, AREA_MAX_Y);
  Screen game_screen = Screen_new(global_view);
  Render render = Render_new(game_screen, 0, AREA_MAX_X * IMG_SCL_X, AREA_MAX_Y * IMG_SCL_Y);
  TextureStorage textures = LoadTextures(render);
  render_set_textureStorage(render, textures);
  GameObject *player = listItem_get(list_first(players));

  Event loop;
  loop.type = LoopEvent;
  addEventListener(loop, movePlayer, EventCallbackArgs_pack(2, area, player));
  GLOBAL_RENDER = render;

  int *rx = malloc(sizeof(int));
  *rx = -1;
  Event key;
  key.type = Keyboard;
  key.key = 'k';
  addEventListener(key, move_board, EventCallbackArgs_pack(4, nishal_left, nishal_right, rx, 0));

  rx = malloc(sizeof(int));
  *rx = 1;
  key.key = 'm';
  addEventListener(key, move_board, EventCallbackArgs_pack(4, nishal_left, nishal_right, rx, 0));

  int *lx = malloc(sizeof(int));
  *lx = -1;
  key.key = 'a';
  addEventListener(key, move_board, EventCallbackArgs_pack(4, nishal_left, nishal_right, 0, lx));

  lx = malloc(sizeof(int));
  *lx = 1;
  key.key = 'z';
  addEventListener(key, move_board, EventCallbackArgs_pack(4, nishal_left, nishal_right, 0, lx));

  key.key = 't';
  addEventListener(key, send_t, NO_ARGS);

//  list_free(players, gameObject_free);
//  list_free(nishal_right, gameObject_free);
//  list_free(nishal_left, gameObject_free);
//  screen_free(game_screen);
//  view_free(global_view);
//  Render_free(render);
//  textureStorage_free(textures);
}