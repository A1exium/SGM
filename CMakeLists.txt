cmake_minimum_required(VERSION 3.17)
project(SGM C)

set(CMAKE_C_STANDARD 11)


add_executable(SGM
        src/main.c src/engine/renders/2D/terminal/console.c src/engine/renders/2D/terminal/console.h src/globals/const.h src/engine/objects/GameObject.c src/engine/objects/GameObject.h src/engine/objects/Area.c src/engine/objects/Area.h src/engine/objects/mod.c src/engine/objects/mod.h src/engine/tools/List.c src/engine/objects/ListGameObject.c src/engine/objects/ListGameObject.h src/engine/tools/serializer.c src/engine/geometry/Position.c src/engine/geometry/Position.h src/engine/renders/2D/base/View.c src/engine/renders/2D/base/View.h src/engine/renders/2D/terminal/Render.c src/engine/renders/2D/base/Render.h src/engine/renders/2D/terminal/Picture.c src/engine/renders/2D/terminal/Picture.h src/engine/renders/2D/terminal/Pixel.c src/engine/renders/2D/terminal/Texture.c src/engine/renders/2D/terminal/Texture.h src/engine/renders/2D/terminal/colors.h src/engine/renders/2D/terminal/Pixel.h src/engine/tools/2DArray.c src/engine/renders/2D/base/Screen.c src/engine/renders/2D/base/Screen.h src/game/start.c src/engine/engine.h src/engine/geometry/mod.h src/engine/renders/2D/mod.h)

target_include_directories(SGM PUBLIC src/engine/tools)
target_include_directories(SGM PUBLIC src/engine)
target_include_directories(SGM PUBLIC src/globals)

IF (WIN32)
    target_sources(SGM PRIVATE src/engine/renders/2D/terminal/win/init_term.c  src/engine/renders/2D/terminal/win/ascii_colors.h)
ELSE()
    target_sources(SGM PRIVATE src/engine/renders/2D/terminal/linx/ascii_colors.h)
ENDIF()
