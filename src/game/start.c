//
// Created by alexium on 11.03.2022.
//

#include "engine.h"
#include <unistd.h>
//#include <SDL2/SDL.h>

enum GameObjectType_t {
  None,
  Tile,
  Player,
  Nishal,
};

//void doInput()
//{
//  SDL_Event event;
//  while (SDL_PollEvent(&event))
//  {
//    switch (event.type)
//    {
//      case SDL_QUIT:
//        exit(0);
//        break;
//
//      default:
//        break;
//    }
//  }
//}

TextureStorage LoadTextures(Render *render) {
  TextureStorage storage = TextureStorage_new(4);
  textureStorage_insert(storage, Player, Texture_load(render, "assets/player.tga"));
  textureStorage_insert(storage, Nishal, Texture_load(render, "assets/nishal.tga"));
  textureStorage_insert(storage, Tile, Texture_load(render, "assets/tile.tga"));
  textureStorage_insert(storage, None, Texture_load(render, "assets/none.tga"));
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
  createObject(Player, AREA_MAX_X / 2, AREA_MAX_Y / 2, 2, area, players);
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
  GameObject *player = listItem_get(list_first(players));

//  SDL_AddTimer(100, Render_timer, render);
//  void *params[] = {player, &area, &dx, &dy};
  int dx = 1, dy = 1;
  while (1) {
    render_render(render);
    Position player_pos = gameObject_get_pos(player);
    int cx = player_pos.x, cy = player_pos.y;
    if (cx == AREA_MAX_X - 1 || cx == 0) {
      dx *= -1;
    }
    if (cy == AREA_MAX_Y - 1 || cy == 0) {
      dy *= -1;
    }
    area_GameObject_move(player, area, dx, dy, 0);
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
    emscripten_sleep(1000);
#else
    sleep(1);
#endif
  }
}