//
// Created by alexium on 11.03.2022.
//

#include "engine.h"
#include "../globals/const.h"
#include <stdio.h>

int serializePosition(GameObject obj, char *dest) {
  Position pos = gameObject_get_pos(obj);
  return sprintf(dest, "%d|%d-", pos.x, pos.y);
}

int deserializePosition(Position *pos, char *dest) {
  return sscanf(dest, "%d|%d-", &pos->x, &pos->y) != 2;
}

enum GameObjectType_t {
  None,
  Tile,
  Player,
  Nishal,
};

typedef enum {
  BoardMoveUp = 1,
  BoardMoveDown = 2,
  PlayerMove = 3,
} BoardMoveType;

void move_board(Event e, EventCallbackArgs args) {
  if (e.type == EventServerMessage && e.payload.server_message_event.sender_id == CLIENT_ID)
    return;

  List left = 0;
  List right = 0;
  int *rx = 0, *lx = 0;
  EventCallbackArgs_unpack(args, &left, &right, &rx, &lx);
  if (rx) {
    int i = 0;
    foreach(GameObject ns = 0, ns, right) {
      if(i == 0 && (gameObject_get_pos(ns).y + *rx == AREA_MAX_Y || gameObject_get_pos(ns).y + *rx == 1))
        break;
      gameObject_move(ns, 0, *rx, 0);
      i++;
    }
  }
  else if (lx) {
    int i = 0;
    foreach(GameObject ns = 0, ns, left) {
      if(i == 0 && (gameObject_get_pos(ns).y + *lx + 2 == AREA_MAX_Y || gameObject_get_pos(ns).y + *lx == -1))
        break;
      gameObject_move(ns, 0, *lx, 0);
      i++;
    }
    if (CLIENT_STATUS) {
      Event multiplayer_move = Event_new(EventCustom);
      event_custom_set_type(&multiplayer_move, *lx > 0 ? BoardMoveUp : BoardMoveDown);
      send_event(multiplayer_move, 0);
    }
  }
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

void movePlayer(Event e, EventCallbackArgs _args) {
//  int *dx, *dy;

//  static int sended = 0;
//  if (e.type == EventServerMessage && e.payload.server_message_event.sender_id == CLIENT_ID)
//    return;
//  if (sended) {
//    if (e.type == EventServerMessage)
//      sended = 0;
//    else
//      return;
//  } else {
//    if (e.type == EventLoop)
//      sended = 1;
//    else
//      return;
//  }

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
//  Event move_event = Event_new(EventCustom);
//  event_custom_set_type(&move_event, PlayerMove);
////  event_custom_set_data(&move_event, player);
////  send_event(move_event, (int (*)(void *, char *)) serializePosition);
//  send_event(move_event, 0);
}

Render GLOBAL_RENDER;

#include <stdlib.h>

//void send_t(Event e, EventCallbackArgs args) {
//  BoardMoveType *move_type = 0;
//  EventCallbackArgs_unpack(args, &move_type);
//  Event t_ev = Event_new(EventCustom);
//  event_custom_set_type(&t_ev, *move_type);
//  send_event(t_ev, 0);
//}

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
  GLOBAL_RENDER = render;

  Event loop = Event_new(EventLoop);
  addEventListener(loop, movePlayer, EventCallbackArgs_pack(2, area, player));

//  Event move_player_live = Event_new(EventServerMessage);
//  move_player_live.payload.server_message_event.custom_event_type = PlayerMove;
//  addEventListener(move_player_live, movePlayer, EventCallbackArgs_pack(2, area, player));

  Event key = Event_new(EventKeyboard);

  int *lx = malloc(sizeof(int));
  *lx = -1;
  event_keyboard_set_key(&key, 'a');
  addEventListener(key, move_board, EventCallbackArgs_pack(4, nishal_left, nishal_right, 0, lx));

  lx = malloc(sizeof(int));
  *lx = 1;
  event_keyboard_set_key(&key, 'z');
  addEventListener(key, move_board, EventCallbackArgs_pack(4, nishal_left, nishal_right, 0, lx));

  Event right_board_move = Event_new(EventServerMessage);
  right_board_move.payload.server_message_event.custom_event_type = BoardMoveUp;
  int *rx = malloc(sizeof(int));
  *rx = -1;
  addEventListener(right_board_move, move_board, EventCallbackArgs_pack(4, nishal_left, nishal_right, rx, 0));

  rx = malloc(sizeof(int));
  *rx = 1;
  right_board_move.payload.server_message_event.custom_event_type = BoardMoveDown;
  addEventListener(right_board_move, move_board, EventCallbackArgs_pack(4, nishal_left, nishal_right, rx, 0));

}