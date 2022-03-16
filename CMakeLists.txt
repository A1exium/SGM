cmake_minimum_required(VERSION 3.17)
project(SGM C)

set(CMAKE_C_STANDARD 11)


if(EMSCRIPTEN)
    message("Compiling to web!")
    set(CMAKE_EXECUTABLE_SUFFIX .html)
    add_link_options(-sWASM -sALLOW_MEMORY_GROWTH)
    add_link_options(--preload-file ../assets/)
ENDIF()

add_executable(SGM src/main.c src/game/start.c src/globals/const.h)
add_subdirectory(src/engine)
target_link_libraries(SGM NHE)
#add_dependencies(SGM NHE)

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
