cmake_minimum_required(VERSION 3.17)
project(SGM C)

set(CMAKE_C_STANDARD 11)


if(EMSCRIPTEN)
    message("Compiling to web!")
    set(CMAKE_EXECUTABLE_SUFFIX .html)
    add_link_options(-sWASM -sALLOW_MEMORY_GROWTH)
    add_link_options(--preload-file ../assets/)
ENDIF()

#add_executable(SGM
#        src/main.c src/engine/renders/2D/terminal/console.c src/engine/renders/2D/terminal/console.h src/globals/const.h src/engine/objects/GameObject.c src/engine/objects/GameObject.h src/engine/objects/Area.c src/engine/objects/Area.h src/engine/objects/mod.c src/engine/objects/mod.h src/engine/tools/List.c src/engine/objects/ListGameObject.c src/engine/objects/ListGameObject.h src/engine/tools/serializer.c src/engine/geometry/Position.c src/engine/geometry/Position.h src/engine/renders/2D/base/View.c src/engine/renders/2D/base/View.h src/engine/renders/2D/terminal/Render.c src/engine/renders/2D/base/Render.h src/engine/renders/2D/terminal/Picture.c src/engine/renders/2D/terminal/Picture.h src/engine/renders/2D/terminal/Pixel.c src/engine/renders/2D/terminal/Texture.c src/engine/renders/2D/terminal/Texture.h src/engine/renders/2D/terminal/colors.h src/engine/renders/2D/terminal/Pixel.h src/engine/tools/2DArray.c src/engine/renders/2D/base/Screen.c src/engine/renders/2D/base/Screen.h src/game/start.c src/engine/engine.h src/engine/geometry/mod.h src/engine/renders/2D/mod.h src/engine/renders/2D/base/TextureStorage.c src/engine/renders/2D/base/TextureStorage.h)
add_executable(SGM src/main.c src/game/start.c src/globals/const.h)
add_subdirectory(src/engine)
target_link_libraries(SGM NHE)

target_include_directories(SGM PUBLIC src/engine/tools)
target_include_directories(SGM PUBLIC src/engine)
target_include_directories(SGM PUBLIC src/globals)

IF(EMSCRIPTEN)
    set_target_properties(SGM PROPERTIES OUTPUT_NAME "index")
ENDIF()

set_target_properties(SGM
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(SGM
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
