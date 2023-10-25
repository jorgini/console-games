#include "ship.h"

ship::ship(std::size_t x) : length(x), is_vertical(true), is_live(true), coord({0, 0}) {}

void ship::move(ship::DIRECTION dir) {
    switch(dir) {
        case UP:
            coord.first = coord.first > 0 ? coord.first - 1 : 0;
            break;
        case DOWN:
            coord.first = (coord.first + length < SIZE && is_vertical) ||
                            (coord.first < SIZE - 1 && !is_vertical) ?
                            coord.first + 1 : coord.first;
            break;
        case LEFT:
            coord.second = coord.second > 0 ? coord.second - 1 : 0;
            break;
        case RIGHT:
            coord.second = (coord.second + length < SIZE && !is_vertical) ||
                          (coord.second < SIZE - 1 && is_vertical) ?
                          coord.second + 1 : coord.second;
            break;
        case NON:
            break;
    }
}

void ship::change_vertical() {
    if (is_vertical) {
        if (coord.second + length <= SIZE)
            is_vertical = !is_vertical;
        else
            return;
    }
    else {
        if (coord.first + length <= SIZE)
            is_vertical = !is_vertical;
        else
            return;
    }
}

const bool& ship::get_vertical() const { return is_vertical; }

std::vector<std::pair<int, int>> ship::get_coord() const {
    std::vector<std::pair<int, int>> ret;
    for (size_t i = 0; i < length; i++) {
        if (is_vertical)
            ret.emplace_back(coord.first + i, coord.second);
        else
            ret.emplace_back(coord.first, coord.second + i);
    }
    return ret;
}

const size_t& ship::get_length() const { return length; }

void ship::set_vertical(bool x) { is_vertical = x; }

void ship::set_coord(std::pair<int, int> x) { coord = x; }