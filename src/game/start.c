//
// Created by alexium on 11.03.2022.
//

#include <stdlib.h>
#include "engine.h"
#include <SDL2/SDL.h>

enum GameObjectType_t {
  None,
  Tile,
  Player,
  Nishal,
};

void doInput(void)
{
  SDL_Event event;

  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT:
        exit(0);
        break;

      default:
        break;
    }
  }
}

TextureStorage LoadTextures(Render *render) {
  TextureStorage storage = TextureStorage_new(4);
  textureStorage_insert(storage, Player, Texture_load(render, "assets/player.png"));
  textureStorage_insert(storage, Nishal, Texture_load(render, "assets/nishal.png"));
  textureStorage_insert(storage, Tile, Texture_load(render, "assets/tile.png"));
  textureStorage_insert(storage, None, Texture_load(render, "assets/none.png"));
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
  Render *render = Render_new(game_screen, 0, AREA_MAX_X * 100, AREA_MAX_Y * 100);
  render_set_textureStorage(render, LoadTextures(render));
  listItem_get(list_first(players));

  render_render(render);
//  while (1) {
//  render_render(render);
//    doInput();
//    SDL_Delay(16);
//  }
}