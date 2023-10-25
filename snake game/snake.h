#ifndef GAMES_SNAKE_H
#define GAMES_SNAKE_H
#include <vector>
#define HIGH 31
#define WIDTH 31

class snake {
private:
    int length;
    std::vector<std::pair<std::size_t, std::size_t>> coord;
    std::pair<std::size_t , std::size_t> fruit;
    std::size_t score;

public:
    enum DIRECTION { UP, DOWN, LEFT, RIGHT, NON};
    bool flag_end_of_game = false;

    snake();
    snake(const snake& other);
    snake& operator=(const snake& other);
    ~snake();

    void move(DIRECTION dir);
    void len_up();
    [[nodiscard]]int get_length() const;
    [[nodiscard]]const std::vector<std::pair<std::size_t, std::size_t>>& get_coord() const;
    [[nodiscard]]DIRECTION get_direction() const;
    DIRECTION& set_direction();

    void print() const;

private:
    DIRECTION direction;
};

#endif
