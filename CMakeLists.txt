cmake_minimum_required(VERSION 3.0.0)
project(UlamSpiral VERSION 0.1.0)

set(SDL2_INCLUDE_DIR  lib/SDL2/include)
set(SDL2_LIB_DIR lib/SDL2/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_library(
    SOURCE_FILES

    src/Framework.h
    src/Framework.cpp

    src/Spiral.h
)

add_executable(UlamSpiral src/main.cpp)
target_link_libraries(${PROJECT_NAME} SOURCE_FILES SDL2 SDL2main)
