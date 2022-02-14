cmake_minimum_required(VERSION 3.21)
project(SGM C)

set(CMAKE_C_STANDARD 11)

add_executable(SGM
        src/main.c src/game.c src/game.h src/visual.c src/visual.h src/const.h src/tools.c src/tools.h)
