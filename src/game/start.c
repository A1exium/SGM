//
// Created by alexium on 11.03.2022.
//

#include "engine.h"

enum GameObjectType_t {
  None,
  Tile,
  Player,
  Nishal,
};

void move_board(EventCallbackArgs args) {
  ListGameObject left = 0;
  ListGameObject right = 0;
  int *rx = 0, *lx = 0;
  Area *area;
  EventCallbackArgs_unpack(args, &area, &left, &right, &rx, &lx);

  if (rx) {
    foreach(e, right) {
      GameObject *ns = listItem_get(e);
      area_GameObject_move(ns, *area, 0, *rx, 0);
    }
  }
  if (lx) {
    foreach(e, left) {
      GameObject *ns = listItem_get(e);
      area_GameObject_move(ns, *area, 0, *lx, 0);
    }
  }
}

TextureStorage LoadTextures(Render *render) {
  TextureStorage storage = TextureStorage_new(4);
  textureStorage_insert(storage, Player, Texture_load(render, get_asset_path("player")));
  textureStorage_insert(storage, Nishal, Texture_load(render, get_asset_path("nishal")));
  textureStorage_insert(storage, Tile, Texture_load(render, get_asset_path("tile")));
  textureStorage_insert(storage, None, Texture_load(render, get_asset_path("none")));
  return storage;
}

void initGame(ListGameObject players, ListGameObject nishals_left, ListGameObject nishals_right, Area area) {
  for (int x = 0; x < AREA_MAX_X; x++) {
    for (int y = 0; y < AREA_MAX_Y; y++) {
      createObject(Tile, x, y, 0, area, 0);
//      if ((y == 0 || y == AREA_MAX_Y - 1) && x % 2 == 0 || (x == 0 || x == AREA_MAX_X - 1) && y % 2 == 0) {
//        createObject(Nishal, x, y, 1, area, nishals);
//      }
    }
  }
  createObject(Nishal, 1, 0, 1, area, nishals_left);
  createObject(Nishal, 2, 1, 1, area, nishals_left);
  createObject(Nishal, 1, 2, 1, area, nishals_left);
  createObject(Nishal, AREA_MAX_X - 2, AREA_MAX_Y - 1, 1, area, nishals_right);
  createObject(Nishal, AREA_MAX_X - 3, AREA_MAX_Y - 2, 1, area, nishals_right);
  createObject(Nishal, AREA_MAX_X - 2, AREA_MAX_Y - 3, 1, area, nishals_right);
  createObject(Player, AREA_MAX_X / 2, AREA_MAX_Y / 2, 2, area, players);
}

void movePlayer(EventCallbackArgs _args) {
//  int *dx, *dy;
  static int dx = 1, dy = 1;
  GameObject *player;
  Area *area;
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
  if (area_get(*area, cx + dx, cy + dy, 1) != 0 || area_get(*area, cx + dx, cy, 1)) {
    if (cx > AREA_MAX_X / 2)
      dx = -1;
    else
      dx = 1;
  }
  area_GameObject_move(player, *area, dx, dy, 0);
}

const EventCallbackArgs NO_ARGS = {
    .length = 0,
    .storage = 0,
};

Render *GLOBAL_RENDER;

_Noreturn void start_game() {
  EventPool_create();
  ListeningTable_init();

  initCurrentRender();
  Area area;
  Area_init(area);
  ListGameObject players = ListGameObject_new();
  ListGameObject nishal_left = ListGameObject_new();
  ListGameObject nishal_right = ListGameObject_new();
  initGame(players, nishal_left, nishal_right, area);
  View *global_view = View_new(&area, 0, 0, AREA_MAX_X, AREA_MAX_Y);
  Screen game_screen = Screen_new(global_view);
  Render *render = Render_new(game_screen, 0, AREA_MAX_X * 3 * 6 * 5, AREA_MAX_Y * 3 * 3 * 8);
  TextureStorage textures = LoadTextures(render);
  render_set_textureStorage(render, textures);
  GameObject *player = listItem_get(list_first(players));



//  Event loop;
//  loop.type = LoopEvent;
//  addEventListener(loop, print_e, NO_ARGS);
//  GLOBAL_RENDER = render;

  Event loop;
  loop.type = LoopEvent;
  addEventListener(loop, movePlayer, EventCallbackArgs_pack(2, &area, player));
  GLOBAL_RENDER = render;

  int *rx = malloc(sizeof(int));
  *rx = -1;
  Event key;
  key.type = Keyboard;
  key.key = 'k';
  addEventListener(key, move_board, EventCallbackArgs_pack(5, &area, nishal_left, nishal_right, rx, 0));


  rx = malloc(sizeof(int));
  *rx = 1;
  key.key = 'm';
  addEventListener(key, move_board, EventCallbackArgs_pack(5, &area, nishal_left, nishal_right, rx, 0));

  int *lx = malloc(sizeof(int));
  *lx = -1;
  key.key = 'a';
  addEventListener(key, move_board, EventCallbackArgs_pack(5, &area, nishal_left, nishal_right, 0, lx));

  lx = malloc(sizeof(int));
  *lx = 1;
  key.key = 'z';
  addEventListener(key, move_board, EventCallbackArgs_pack(5, &area, nishal_left, nishal_right, 0, lx));
  GLOBAL_RENDER = render;


//  list_free(players, gameObject_free);
//  list_free(nishal_right, gameObject_free);
//  list_free(nishal_left, gameObject_free);
//  screen_free(game_screen);
//  view_free(global_view);
//  Render_free(render);
//  textureStorage_free(textures);
  startEventLoop();
}