//
// Created by alexium on 11.02.2022.
//
#include "./engine/renders/2D/terminal/console.h"
#include "engine/objects/mod.h"
#include "engine/renders/2D/base/View.h"
#include "engine/renders/2D/base/Render.h"

// ADMIN LOH
// Second dev tozhe loh.

_Noreturn extern void start_game();

int main() {
//#ifdef __EMSCRIPTEN__
//#include <emscripten.h>
//  emscripten_set_main_loop(start_game, 60, 1);
//#else
  start_game();
//#endif
}