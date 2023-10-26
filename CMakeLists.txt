cmake_minimum_required(VERSION 3.22)
project(games)

set(CMAKE_CXX_STANDARD 17)

add_executable(snake "snake game/board.cpp" "snake game/snake.cpp" "snake game/snake.h")

add_executable(sea_fight "SEA FIGHT/sea_fight.cpp" "SEA FIGHT/ship.h" "SEA FIGHT/field.h" "SEA FIGHT/ship.cpp" "SEA FIGHT/field.cpp")

add_executable(2048 "2048 game/field2048.cpp" "2048 game/field2048.h" "2048 game/main2048.cpp")