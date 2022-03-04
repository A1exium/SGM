cmake_minimum_required(VERSION 3.20)
project(SGM C)

set(CMAKE_C_STANDARD 11)

add_executable(SGM
        src/main.c src/engine/renders/2D/terminal/console.c src/engine/renders/2D/terminal/console.h src/globals/const.h src/engine/objects/GameObject.c src/engine/objects/GameObject.h src/engine/objects/Area.c src/engine/objects/Area.h src/engine/objects/mod.c src/engine/objects/mod.h src/engine/tools/List.c src/engine/tools/List.h src/engine/renders/2D/terminal/mod.c src/engine/renders/2D/terminal/mod.h src/engine/objects/ListGameObject.c src/engine/objects/ListGameObject.h src/engine/tools/serializer.c src/engine/tools/serializer.h src/engine/geometry/Position.c src/engine/geometry/Position.h src/game/Init.c src/game/Init.h src/game/cycle.c src/game/cycle.c src/game/cycle.h src/engine/renders/2D/abstractions/Screen.c src/engine/renders/2D/abstractions/Screen.h src/engine/renders/2D/abstractions/View.c src/engine/renders/2D/abstractions/View.h src/engine/renders/2D/abstractions/Render.c src/engine/renders/2D/abstractions/Render.h src/engine/renders/2D/abstractions/Picture.c src/engine/renders/2D/abstractions/Picture.h src/engine/renders/2D/default/Pixel.c src/engine/renders/2D/default/Pixel.h)
