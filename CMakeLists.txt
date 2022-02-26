cmake_minimum_required(VERSION 3.21)
project(SGM C)

set(CMAKE_C_STANDARD 11)

add_executable(SGM
        src/main.c src/io/output/console.c src/io/output/console.h src/const.h src/game/GameObject.c src/game/GameObject.h src/game/Area.c src/game/Area.h src/game/mod.c src/game/mod.h src/tools/List.c src/tools/List.h src/io/output/mod.c src/io/output/mod.h src/game/ListGameObject.c src/game/ListGameObject.h src/tools/serializer.c src/tools/serializer.h src/game/Position.c src/game/Position.h)
