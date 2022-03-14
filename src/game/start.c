//
// Created by alexium on 11.03.2022.
//

#include <stdlib.h>
#include "engine.h"
#include "renders/2D/terminal/Texture.h"

enum GameObjectType_t {
  None,
  Tile,
  Player,
  Nishal,
};

TextureStorage LoadTextures() {
  TextureStorage storage = TextureStorage_new(4);
  textureStorage_insert(storage, Player, Texture_load(fopen("../assets/player.nsd", "r")));
  textureStorage_insert(storage, Nishal, Texture_load(fopen("../assets/nishal.nsd", "r")));
  textureStorage_insert(storage, Tile, Texture_load(fopen("../assets/tile.nsd", "r")));
  textureStorage_insert(storage, None, Texture_load(fopen("../assets/none.nsd", "r")));
  return storage;
}

void initGame(ListGameObject players, ListGameObject nishals, Area area) {
  for (int x = 0; x < AREA_MAX_X; x++) {
    for (int y = 0; y < AREA_MAX_Y; y++) {
      createObject(Tile, x, y, 0, area, 0);
      if ((y == 0 || y == AREA_MAX_Y - 1) && x % 2 == 0 || (x == 0 || x == AREA_MAX_X - 1) && y % 2 == 0) {
        createObject(Nishal, x, y, 1, area, nishals);
      }
    }
  }
  createObject(Player, AREA_MAX_X / 2, AREA_MAX_Y / 2, 1, area, players);
}

void start_game() {
//  SetConsoleMode()
  initCurrentRender();
  Area area;
  Area_init(area);
  ListGameObject players = ListGameObject_new();
  ListGameObject nishals = ListGameObject_new();
  initGame(players, nishals, area);
  View *global_view = View_new(&area, 0, 0, AREA_MAX_X, AREA_MAX_Y);
  Screen game_screen = Screen_new(global_view);
  Render *render = Render_new(game_screen, LoadTextures(), AREA_MAX_X * 3, AREA_MAX_Y * 3);
  listItem_get(list_first(players));

#include <stdio.h>
  render_render(render);
  int ch = getchar();
  while (ch != 'q') {
    int dx = 0, dy = 0;
    if (ch == 'w')
      dy = -1;
    if (ch == 's')
      dy = 1;
    if (ch == 'a')
      dx = -1;
    if (ch == 'd')
      dx = 1;

    area_GameObject_move(listItem_get(list_first(players)), area, dx, dy, 0);
    render_render(render);
    ch = getchar();
  }
}