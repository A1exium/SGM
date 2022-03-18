//
// Created by alexium on 11.03.2022.
//

#include "engine.h"
//#include <SDL2/SDL.h>

enum GameObjectType_t {
  None,
  Tile,
  Player,
  Nishal,
};


#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#elif WIN32
#include <windows.h>
#elif _POSIX_C_SOURCE >= 199309L
#include <time.h>   // for nanosleep
#else
#include <unistd.h> // for usleep
#endif

void sleep_ms(int milliseconds){ // cross-platform sleep function
#ifdef __EMSCRIPTEN__
  emscripten_sleep(milliseconds);
#elif WIN32
  Sleep(milliseconds);
#elif _POSIX_C_SOURCE >= 199309L
  struct timespec ts;
  ts.tv_sec = milliseconds / 1000;
  ts.tv_nsec = (milliseconds % 1000) * 1000000;
  nanosleep(&ts, NULL);
#else
  if (milliseconds >= 1000)
      sleep(milliseconds / 1000);
    usleep((milliseconds % 1000) * 1000);
#endif
}

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
  textureStorage_insert(storage, Player, Texture_load(render, "assets/player"));
  textureStorage_insert(storage, Nishal, Texture_load(render, "assets/nishal"));
  textureStorage_insert(storage, Tile, Texture_load(render, "assets/tile"));
  textureStorage_insert(storage, None, Texture_load(render, "assets/none"));
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

_Noreturn void start_game() {
//  SetConsoleMode()
  initCurrentRender();
  Area area;
  Area_init(area);
  ListGameObject players = ListGameObject_new();
  ListGameObject nishals = ListGameObject_new();
  initGame(players, nishals, area);
  View *global_view = View_new(&area, 0, 0, AREA_MAX_X, AREA_MAX_Y);
  Screen game_screen = Screen_new(global_view);
  Render *render = Render_new(game_screen, 0, AREA_MAX_X * 3 * 6 * 5, AREA_MAX_Y * 3 * 3 * 10);
  TextureStorage textures = LoadTextures(render);
  render_set_textureStorage(render, textures);
  GameObject *player = listItem_get(list_first(players));

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
    sleep_ms(100);
  }
  list_free(players, gameObject_free);
  list_free(nishals, gameObject_free);
  screen_free(game_screen);
  view_free(global_view);
  Render_free(render);
  textureStorage_free(textures);
}