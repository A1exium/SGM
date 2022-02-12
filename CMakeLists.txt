cmake_minimum_required(VERSION 3.21)
project(SGM C)

set(CMAKE_C_STANDARD 11)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(SGM
        main.c game.c game.h visual.c visual.h const.h)

target_link_libraries(SGM ${CURSES_LIBRARIES})