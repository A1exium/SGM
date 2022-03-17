cmake_minimum_required(VERSION 3.17)
project(SGM C)

set(CMAKE_C_STANDARD 11)


add_executable(SGM src/main.c src/game/start.c src/globals/const.h)
add_subdirectory(src/engine)
target_link_libraries(SGM NHE)

target_include_directories(SGM PUBLIC src/engine/tools)
target_include_directories(SGM PUBLIC src/engine)
target_include_directories(SGM PUBLIC src/globals)

if(EMSCRIPTEN)
    message("Compiling to web!")
    set(CMAKE_EXECUTABLE_SUFFIX .html)
    target_link_options(SGM PRIVATE -sWASM -sALLOW_MEMORY_GROWTH)
    target_link_options(SGM PRIVATE --preload-file ../assets/)
    set_target_properties(SGM PROPERTIES OUTPUT_NAME "index")
ENDIF()

set_target_properties(SGM
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(SGM
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
