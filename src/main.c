//
// Created by alexium on 11.02.2022.
//
//#include "engine.h"

// ADMIN LOH
// Second dev tozhe loh.

extern void start_game();

#include "engine_init.h"

int main() {
  EventPool_create();
  ListeningTable_init();
  start_game();
  start_event_loop();
}