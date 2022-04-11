cmake_minimum_required(VERSION 3.17)
project(SGM C)

set(CMAKE_C_STANDARD 11)

include(cfg/build-cfg.txt)

add_executable(SGM src/main.c src/game/start.c src/globals/const.h)
add_subdirectory(src/engine)
target_link_libraries(SGM NHE-base)

target_include_directories(SGM PUBLIC src/engine/tools)
target_include_directories(SGM PUBLIC src/engine)
target_include_directories(SGM PUBLIC src/globals)

if(EMSCRIPTEN)
    message("Compiling to web!")
    set(CMAKE_EXECUTABLE_SUFFIX .html)
    target_link_options(SGM PRIVATE -sWASM -sALLOW_MEMORY_GROWTH -sASYNCIFY)
    target_link_options(SGM PRIVATE -sWEBSOCKET_SUBPROTOCOL='null')
    target_link_options(SGM PRIVATE --preload-file ../assets/)
    set_target_properties(SGM PROPERTIES OUTPUT_NAME "index")
ENDIF()

target_compile_options(SGM PUBLIC -O3)
target_link_options(SGM PUBLIC -O3)

set_target_properties(SGM
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(SGM
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

