#include "snake.h"
#include "conio.h"
#include <iostream>


int main() {
    snake _snake;

    unsigned long long timer = clock();
    while(!_snake.flag_end_of_game) {
        if(_kbhit()) {
            switch (_getch()) {
                case 'a' :
                    _snake.set_direction() = snake::LEFT;
                    break;
                case 'w' :
                    _snake.set_direction() = snake::UP;
                    break;
                case 'd' :
                    _snake.set_direction() = snake::RIGHT;
                    break;
                case 's' :
                    _snake.set_direction() = snake::DOWN;
                    break;
                default:
                    break;
            }
        }
        _snake.move(_snake.get_direction());
        _snake.len_up();
        _snake.print();
        while (clock() - timer < 500) {}
        timer = clock();
    }
    std::cout << std::endl << "Loose!" << std::endl;
    system("pause");

    return 0;
}
