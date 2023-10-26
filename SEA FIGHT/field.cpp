#include "field.h"
#include "../2048 game/field2048.h"

#include <ctime>
#include <random>

std::pair<int, int> operator+(std::pair<int, int> first, std::pair<int, int> second) {
    return {first.first + second.first, first.second + second.second};
}

std::pair<int, int> operator-(std::pair<int, int> first, std::pair<int, int> second) {
    return {first.first - second.first, first.second - second.second};
}

field::field() : ships({ship(4),
                        ship(3), ship(3),
                        ship(2), ship(2), ship(2),
                        ship(1), ship(1), ship(1), ship(1),}),
                        map(std::vector<std::vector<bool>>(SIZE, std::vector<bool>(SIZE, false))),
                        cur(0) {}

bool field::put_ship() {
    if (check_pos_valid(ships[cur])) {
        cur++;
        return true;
    }
    return false;
}

bool field::check_pos_valid(const ship &obj) const {
    bool flag_is_valid = true;

    std::pair<int, int> diff[] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    std::vector<std::pair<int, int>> first = obj.get_coord();

    if (obj.get_vertical() && first[0].first + obj.get_length() > SIZE)
        return false;
    if (!obj.get_vertical() && first[0].second + obj.get_length() > SIZE)
        return false;

    for (size_t i = 0; i < cur; i++) {
        std::vector<std::pair<int, int>> second = ships[i].get_coord();
        for (auto & j : second) {
            for (auto & m : first) {
                for (auto & k : diff) {
                    if (m + k == j) {
                        flag_is_valid = false;
                        break;
                    }
                }
                if (!flag_is_valid) break;
            }
            if (!flag_is_valid) break;
        }
        if (!flag_is_valid) break;
    }
    return flag_is_valid;
}

void field::public_print() const {
    std::cout << " |ABCDEFGHIJ" << std::endl << "------------" << std::endl;
    for (size_t i = 0; i < SIZE; i++) {
        std::cout << i << "|";
        for (size_t j = 0; j < SIZE; j++) {
            bool flag = false;
            for (size_t k = 0; k <= (cur <= 9 ? cur : SIZE - 1); k++) {
                std::vector<std::pair<int, int>> obj = ships[k].get_coord();
                for (auto m : obj) {
                    std::pair<int, int> that = {i, j};
                    if (that == m) {
                        std::cout << (map[i][j] ? "X" : "0");
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }

            if (!flag) std::cout << (map[i][j] ? "*" : " ");
        }
        std::cout << std::endl;
    }
}

void field::private_print() const {
    std::cout << " |ABCDEFGHIJ" << std::endl << "------------" << std::endl;
    for (size_t i = 0; i < SIZE; i++) {
        std::cout << i << "|";
        for (size_t j = 0; j < SIZE; j++) {
            bool flag = false;
            for (size_t k = 0; k < cur; k++) {
                std::vector<std::pair<int, int>> obj = ships[k].get_coord();
                for (auto m : obj) {
                    std::pair<int, int> that = {i, j};
                    if (that == m && map[i][j]) {
                        std::cout << "X";
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }

            if (!flag) std::cout << (map[i][j] ? "*" : " ");
        }
        std::cout << std::endl;
    }
}

int field::shoot(std::pair<int, int> target) {
    if (target.first < 0 || target.first > 9 || target.second < 0 || target.second > 9) return WRONG_SHOT;

    if (map[target.first][target.second]) return WRONG_SHOT;

    map[target.first][target.second] = true;

    bool hit = false;

    for (auto & el : ships) {
        if (!el.is_live)
            continue;

        std::vector<std::pair<int, int>> coord = el.get_coord();
        bool flag = true;
        for (auto k : coord) {
            if (!map[k.first][k.second])
                flag = false;
            if (k == target)
                hit = true;
        }

        if (flag) {
            for (auto k : coord) {
                k.first + 1 < SIZE ? map[k.first + 1][k.second] = true : 1 + 1;
                k.first - 1 >= 0 ? map[k.first - 1][k.second] = true : 1 + 1;
                k.second + 1 < SIZE ? map[k.first][k.second + 1] = true : 1 + 1;
                k.second - 1 >= 0 ? map[k.first][k.second - 1] = true : 1 + 1;
                (k.first - 1 >= 0 && k.second - 1 >= 0) ? map[k.first - 1][k.second - 1] = true : 1 + 1;
                (k.first + 1 < SIZE && k.second - 1 >= 0) ? map[k.first + 1][k.second - 1] = true : 1 + 1;
                (k.first - 1 >= 0 && k.second + 1 < SIZE) ? map[k.first - 1][k.second + 1] = true : 1 + 1;
                (k.first + 1 < SIZE && k.second + 1 < SIZE) ? map[k.first + 1][k.second + 1] = true : 1 + 1;
            }
            el.is_live = false;
            return DESTRUCTION;
        }
    }
    return hit ? HIT : MISS;
}

bool field::check_game_over() const {
    bool flag = true;
    for (auto el : ships) {
        if (el.is_live)
            flag = false;
    }
    return flag;
}

bool field::check_ready() const { return cur == 10; }

ship& field::get_cur_ship() { return ships[cur]; }

void field::random_set() {
    srand(time(NULL));

    while(cur != 10) {
        std::pair<int, int> pos = {rand() % 10, rand() % 10};
        bool is_vertical = rand() % 2;
        ships[cur].set_coord(pos);
        ships[cur].set_vertical(is_vertical);
        put_ship();
    }
}