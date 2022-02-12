//
// Created by alexium on 11.02.2022.
//

#include "visual.h"
#include <stdio.h>
#include <curses.h>

typedef struct Render_s {
  WINDOW *scr;
} Render;

Render render;

void render_init() {
  render.scr = initscr();
  resizeterm(AREA_W + 2, AREA_H + 2);
}

void print_hborder() {
  for (int i = 0; i < AREA_W + 2; i++)
    addch('-');
}

void print(Object area[AREA_H][AREA_W]) {
  clear();
  print_hborder();
  for (int y = 0; y < AREA_H; y++) {
    addch('|');
    for (int x = 0; x < AREA_W; x++) {
      switch (area[y][x].type) {
        case Player:addch('#');
          break;
        case Nishal:addch('*');
          break;
        default:addch(' ');
          break;
      }
    }
    addch('|');
  }
  print_hborder();
  refresh();
}