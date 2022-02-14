cmake_minimum_required(VERSION 3.21)
project(SGM C)

set(CMAKE_C_STANDARD 11)

add_executable(SGM
        main.c game.c game.h visual.c visual.h const.h tools.c tools.h)

add_custom_target(WEB)