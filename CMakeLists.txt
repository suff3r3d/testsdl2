cmake_minimum_required(VERSION 3.7)

add_compile_definitions(SCREEN_HEIGHT=720)
add_compile_definitions(SCREEN_WIDTH=1280)
add_compile_definitions(gravity=9.8)
add_compile_definitions(delta=33.3333333e-3f)

project(SDL2Test)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(SDL2Test src/Main.cpp src/Player/Player.cpp src/Ball/Ball.cpp src/Gun/Gun.cpp src/Stuff/Stuff.cpp)
target_link_libraries(SDL2Test ${SDL2_LIBRARIES})