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

#include <SDL2/SDL.h>
void doInput(int *dx, int *dy, ListGameObject left, ListGameObject right, Area area)
{
  SDL_Event event;
  int lx = 0, rx = 0;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT:
        exit(0);
        break;
      case SDL_KEYDOWN:
        fflush(stdout);
        if (event.key.keysym.sym == SDLK_LEFT) {
          *dx = -1;
        } else if (event.key.keysym.sym == SDLK_RIGHT) {
          *dx = 1;
        } else if (event.key.keysym.sym == SDLK_UP) {
          *dy = -1;
        } else if (event.key.keysym.sym == SDLK_DOWN) {
          *dy = 1;
        } else if (event.key.keysym.sym == SDLK_a) {
          lx = -1;
        } else if (event.key.keysym.sym == SDLK_z) {
          lx = 1;
        } else if (event.key.keysym.sym == SDLK_k) {
          rx = -1;
        } else if (event.key.keysym.sym == SDLK_m) {
          rx = 1;
        }
        break;
      default:
        break;
    }
  }
  if (rx) {
    foreach(e, right) {
      GameObject *ns = listItem_get(e);
      area_GameObject_move(ns, area, 0, rx, 0);
    }
  }
  if (lx) {
    foreach(e, left) {
      GameObject *ns = listItem_get(e);
      area_GameObject_move(ns, area, 0, lx, 0);
    }
  }
}

TextureStorage LoadTextures(Render *render) {
  TextureStorage storage = TextureStorage_new(4);
  textureStorage_insert(storage, Player, Texture_load(render, "assets/player"));
  textureStorage_insert(storage, Nishal, Texture_load(render, "assets/nishal"));
  textureStorage_insert(storage, Tile, Texture_load(render, "assets/tile"));
  textureStorage_insert(storage, None, Texture_load(render, "assets/none"));
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

_Noreturn void start_game() {
//  SetConsoleMode()
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

  int dx = 1, dy = 1;
  while (1) {
    render_render(render);
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
    area_GameObject_move(player, area, dx, dy, 0);
    doInput(&dx, &dy, nishal_left, nishal_right, area);
    sleep_ms(100);
  }
  list_free(players, gameObject_free);
  list_free(nishal_right, gameObject_free);
  list_free(nishal_left, gameObject_free);
  screen_free(game_screen);
  view_free(global_view);
  Render_free(render);
  textureStorage_free(textures);
}