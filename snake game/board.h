#ifndef GAMES_BOARD_H
#define GAMES_BOARD_H
#define HIGH 51
#define WIDTH 51
#include "snake.h"
#include <array>
#include <iostream>

class board {
private:
    std::array<std::array<std::size_t, WIDTH>, HIGH> map;

public:
    void print(const snake& _snake);

};

#endif //GAMES_BOARD_H
