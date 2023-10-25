#ifndef GAMES_FIELD_H
#define GAMES_FIELD_H
#include <vector>
#include "ship.h"
#include <iostream>

std::pair<int, int> operator+(std::pair<int, int> first, std::pair<int, int> second);

std::pair<int, int> operator-(std::pair<int, int> first, std::pair<int, int> second);

class field {
private:
    std::vector<ship> ships;
    std::vector<std::vector<bool>> map;
    size_t cur;

public:
    field();
    field(const field& other) = delete;
    field& operator=(const field& other) = delete;
    ~field() = default;

    void put_ship();
    bool check_pos_valid(const ship& obj) const;
    void public_print() const;
    void private_print() const;
    int shoot(std::pair<int, int> target);
    bool check_game_over() const;
    bool check_ready() const;
    ship& get_cur_ship();

    void random_set();
};


#endif //GAMES_FIELD_H
