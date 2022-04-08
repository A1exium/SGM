//
// Created by alexium on 11.02.2022.
//
//#include "engine.h"

// ADMIN LOH
// Second dev tozhe loh.

extern void start_game();

#include "engine_init.h"
#include "stdio.h"

int main() {
  EventPool_create();
  ListeningTable_init();
  int tmp = getchar();
  if (tmp == 's') {
    serverInit("127.0.0.1", 48666);
  } else {
    clientInit("127.0.0.1", 48666);
  }
  start_game();
  start_event_loop();
}