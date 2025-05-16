cmake_minimum_required(VERSION 3.7)

add_compile_definitions(SCREEN_HEIGHT=720)
add_compile_definitions(SCREEN_WIDTH=1280)
add_compile_definitions(gravity=9.8)
add_compile_definitions(delta=33.3333333e-3f)

project(space_shooter)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(space_shooter src/Main.cpp src/Player/Player.cpp src/Ball/Ball.cpp src/Cannon/Cannon.cpp src/Stuff/Stuff.cpp src/BoostBox/BoostBox.cpp)
target_link_libraries(space_shooter ${SDL2_LIBRARIES})