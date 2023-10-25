#include "snake.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

//template<std::size_t HIGH, std::size_t WIDTH>
snake::snake() : length(1), coord(1, {HIGH / 2, WIDTH / 2}), direction(NON),
                score(0), fruit({rand() % (HIGH - 1) + 1, rand() % (WIDTH - 1) + 1}) {}
//template<std::size_t HIGH, std::size_t WIDTH>
snake::snake(const snake& other) = default;
//template<std::size_t HIGH, std::size_t WIDTH>
snake& snake::operator=(const snake& other) = default;
//template<std::size_t HIGH, std::size_t WIDTH>
snake::~snake() = default;

//template<std::size_t HIGH, std::size_t WIDTH>
void snake::move(DIRECTION dir) {
    score += 10;
    std::size_t last = coord.size() - 1;
    for (std::size_t i = 0; i < last; i++)
        coord[i] = coord[i + 1];

    switch(dir) {
        case UP :
            coord[last].first = coord[last].first == 0 ? HIGH : --coord[last].first;
            break;
        case DOWN :
            coord[last].first = coord[last].first == HIGH - 1 ? 0 : ++coord[last].first;
            break;
        case LEFT :
            coord[last].second = coord[last].second == 0 ? WIDTH : --coord[last].second;
            break;
        case RIGHT :
            coord[last].second = coord[last].second == WIDTH - 1 ? 0 : ++coord[last].second;
            break;
        case NON :
            break;
    }

    for (std::size_t i = 0; i < last; i++)
        if (coord[last] == coord[i])
            flag_end_of_game = true;
}

//template<std::size_t HIGH, std::size_t WIDTH>
void snake::len_up() {
    std::size_t last = coord.size() - 1;
    if (coord[last] != fruit)
        return;

    ++length;
    switch(direction) {
        case UP :
            coord.emplace_back(coord[last].first - 1, coord[last].second);
            if (coord[coord.size() - 1].first < 0)
                coord[coord.size() - 1].first = HIGH;
            break;
        case DOWN :
            coord.emplace_back(coord[last].first + 1, coord[last].second);
            if (coord[coord.size() - 1].first >= HIGH)
                coord[coord.size() - 1].first = 0;
            break;
        case LEFT :
            coord.emplace_back(coord[last].first, coord[last].second - 1);
            if (coord[coord.size() - 1].second < 0)
                coord[coord.size() - 1].first = HIGH;
            break;
        case RIGHT :
            coord.emplace_back(coord[last].first, coord[last].second + 1);
            if (coord[coord.size() - 1].first >= HIGH)
                coord[coord.size() - 1].first = 0;
            break;
        case NON :
            flag_end_of_game = true;
            break;
    }

    srand(time(nullptr));
    fruit.first = rand() % (HIGH - 1) + 1;
    fruit.second = rand() % (WIDTH - 1) + 1;
}

//template<std::size_t HIGH, std::size_t WIDTH>
[[nodiscard]] int snake::get_length() const { return length; }

//template<std::size_t HIGH, std::size_t WIDTH>
[[nodiscard]]const std::vector<std::pair<std::size_t, std::size_t>>& snake::get_coord() const { return coord; }

//template<std::size_t HIGH, std::size_t WIDTH>
[[nodiscard]]snake::DIRECTION snake::get_direction() const { return direction; }

snake::DIRECTION& snake::set_direction() { return direction; }

//template<std::size_t HIGH, std::size_t WIDTH>
void snake::print() const {
    system("cls");

    for (std::size_t i = 0; i <= HIGH; i++) {
        for (std::size_t j = 0; j <= WIDTH; j++) {
            if (i == fruit.first && j == fruit.second)
                std::cout << "F";
            else if (i == 0 || i == HIGH)
                std::cout << "-";
            else if (j == 0 || j == WIDTH)
                std::cout << "|";
            else {
                bool flag = true;
                for (std::size_t k = 0; k < length; k++) {
                    if (i == coord[k].first && j == coord[k].second) {
                        if (k == length - 1) {
                            switch (direction) {
                                case UP :
                                    std::cout << "^";
                                    break;
                                case DOWN :
                                    std::cout << "/";
                                    break;
                                case LEFT :
                                    std::cout << "<";
                                    break;
                                case RIGHT :
                                    std::cout << ">";
                                    break;
                                case NON :
                                    break;
                            }
                        }
                        else
                            std::cout << "*";
                        flag = false;
                    }
                }
                if (flag)
                    std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << "score: " << length * 100 << std::endl;
}
