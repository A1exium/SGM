//
// Created by alexium on 11.02.2022.
//
//#include "engine.h"

// ADMIN LOH
// Second dev tozhe loh.

_Noreturn extern void start_game();


int main() {
//#ifdef __EMSCRIPTEN__
//#include <emscripten.h>
//  emscripten_set_main_loop(start_game, 60, 1);
//#else
//  EventPool_create();
//  ListeningTable_init();
  start_game();
//  startEventLoop();
//#endif
}