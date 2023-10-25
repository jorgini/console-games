#ifndef GAMES_SHIP_H
#define GAMES_SHIP_H
#define SIZE 10
#include <iostream>
#include <vector>

class ship {
private:
    std::pair<int, int> coord;
    std::size_t length;
    bool is_vertical;


public:
    enum DIRECTION { UP, DOWN, LEFT, RIGHT, NON};
    bool is_live;

    ship() = delete;
    explicit ship(size_t x);
    ship(const ship& other) = default;
    ship& operator=(const ship& other) = default;
    ~ship() = default;

    void move(DIRECTION dir);
    void change_vertical();
    const bool& get_vertical() const;
    std::vector<std::pair<int, int>> get_coord() const;
    const size_t& get_length() const;

    void set_vertical(bool x);
    void set_coord(std::pair<int, int> x);
};

#endif //GAMES_SHIP_H
