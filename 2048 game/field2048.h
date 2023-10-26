#ifndef GAMES_FIELD_2048_H
#define GAMES_FIELD_2048_H

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#define END 404
#define INCORRECT 202
#define CORRECT 1

enum DIRECTION {
    LEFT = 0,
    UP = 1,
    RIGHT = 2,
    DOWN = 3
};

class field {
private:
    std::vector<std::vector<unsigned>> numbers;
    size_t score;
    std::mt19937 gen;
    size_t SIZE;

public:
    explicit field(size_t SIZE);

    int push(DIRECTION dir);
    size_t get_score() const;

    friend std::ostream& operator<<(std::ostream& os, const field& f);
};



#endif //GAMES_FIELD_2048_H
