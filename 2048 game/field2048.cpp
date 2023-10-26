#include "field2048.h"

field::field(size_t SIZE) {
    numbers = std::vector<std::vector<unsigned>>(SIZE, std::vector<unsigned>(SIZE, 0));
    gen = std::mt19937(time(nullptr));
    score = 0;
    this->SIZE = SIZE;

    numbers[gen() % SIZE][gen() % SIZE] = pow(2, (gen() % 3) + 1);
}

int field::push(DIRECTION dir) {
    bool right = false;
    switch (dir) {
        case LEFT:
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    if (numbers[i][j] != 0) {
                        int k = j - 1;
                        while (k >= 0 && numbers[i][k] == 0) {
                            numbers[i][k] = numbers[i][k + 1];
                            numbers[i][k + 1] = 0;
                            right = true;
                            k--;
                        }
                    }
                }

                for (int j = 0; j < SIZE - 1; ++j) {
                    if (numbers[i][j] == numbers[i][j + 1] && numbers[i][j] != 0) {
                        numbers[i][j] *= 2;
                        numbers[i][j + 1] = 0;
                        right = true;
                    }

                }

                for (int j = 0; j < SIZE; ++j) {
                    if (numbers[i][j] != 0 && numbers[i][j - 1] == 0) {
                        int k = j - 1;
                        while (k >= 0 && numbers[i][k] == 0) {
                            numbers[i][k] = numbers[i][k + 1];
                            numbers[i][k + 1] = 0;
                            k--;
                        }
                    }
                }
            }
            break;
        case UP:
            for (int j = 0; j < SIZE; ++j) {
                for (int i = 0; i < SIZE; ++i) {
                    if (numbers[i][j] != 0) {
                        int k = i - 1;
                        while (k >= 0 && numbers[k][j] == 0) {
                            numbers[k][j] = numbers[k + 1][j];
                            numbers[k + 1][j] = 0;
                            right = true;
                            k--;
                        }
                    }
                }

                for (int i = 0; i < SIZE - 1; ++i) {
                    if (numbers[i][j] == numbers[i + 1][j] && numbers[i][j] != 0) {
                        numbers[i][j] *= 2;
                        numbers[i + 1][j] = 0;
                        right = true;
                    }

                }

                for (int i = 0; i < SIZE; ++i) {
                    if (numbers[i][j] != 0) {
                        int k = i - 1;
                        while (k >= 0 && numbers[k][j] == 0) {
                            numbers[k][j] = numbers[k + 1][j];
                            numbers[k + 1][j] = 0;
                            k--;
                        }
                    }
                }
            }
            break;
        case RIGHT:
            for (int i = 0; i < SIZE; ++i) {
                for (int j = SIZE - 1; j >= 0; --j) {
                    if (numbers[i][j] != 0) {
                        int k = j + 1;
                        while (k < SIZE && numbers[i][k] == 0) {
                            numbers[i][k] = numbers[i][k - 1];
                            numbers[i][k - 1] = 0;
                            right = true;
                            k++;
                        }
                    }
                }

                for (int j = SIZE - 1; j > 0; --j) {
                    if (numbers[i][j] == numbers[i][j - 1] && numbers[i][j] != 0) {
                        numbers[i][j] *= 2;
                        numbers[i][j - 1] = 0;
                        right = true;
                    }

                }

                for (int j = SIZE - 1; j >= 0; --j) {
                    if (numbers[i][j] != 0) {
                        int k = j + 1;
                        while (k < SIZE && numbers[i][k] == 0) {
                            numbers[i][k] = numbers[i][k - 1];
                            numbers[i][k - 1] = 0;
                            k++;
                        }
                    }
                }
            }
            break;
        case DOWN:
            for (int j = 0; j < SIZE; ++j) {
                for (int i = SIZE - 1; i >= 0; --i) {
                    if (numbers[i][j] != 0) {
                        int k = i + 1;
                        while (k < SIZE && numbers[k][j] == 0) {
                            numbers[k][j] = numbers[k - 1][j];
                            numbers[k - 1][j] = 0;
                            right = true;
                            k++;
                        }
                    }
                }

                for (int i = SIZE - 1; i > 0; --i) {
                    if (numbers[i][j] == numbers[i - 1][j] && numbers[i][j] != 0) {
                        numbers[i][j] *= 2;
                        numbers[i - 1][j] = 0;
                        right = true;
                    }
                }

                for (int i = SIZE - 1; i >= 0; --i) {
                    if (numbers[i][j] != 0) {
                        int k = i + 1;
                        while (k < SIZE && numbers[k][j] == 0) {
                            numbers[k][j] = numbers[k - 1][j];
                            numbers[k - 1][j] = 0;
                            k++;
                        }
                    }
                }
            }
            break;
    }

    unsigned new_num = pow(2, (gen() % 3) + 1);
    bool flag = false;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (numbers[i][j] == 0) {
                flag = true;
                break;
            }
        }
    }

    if (right) {
        while (true) {
            unsigned x = gen() % SIZE;
            unsigned y = gen() % SIZE;

            if (numbers[x][y] == 0) {
                numbers[x][y] = new_num;
                break;
            }
        }
        score += 10;
        return CORRECT;
    }

    return flag ? INCORRECT : END;
}

std::ostream &operator<<(std::ostream& os, const field& f) {
    os << std::endl << std::endl;
    for (int row = 0; row < 6 * f.SIZE + 1; ++row) {
        os << "\t";
        if (row % 6 == 0) {
            for (int col = 0; col < 6 * f.SIZE + 1; ++col)
                os << "*";
            os << std::endl;
            continue;
        }

        for (int col = 0; col < 6 * f.SIZE + 1; ++col) {
            if (col % 6 == 0)
                os << "*";
            else if (row % 6 == 3 && col % 6 == 1) {
                if (f.numbers[row / 6][col / 6] == 0)
                    os << "     ";
                else if (f.numbers[row / 6][col / 6] < 10)
                    os << "  " << f.numbers[row / 6][col / 6] << "  ";
                else if (f.numbers[row / 6][col / 6] < 100)
                    os << " " << f.numbers[row / 6][col / 6] << "  ";
                else if (f.numbers[row / 6][col / 6] < 1000)
                    os << " " << f.numbers[row / 6][col / 6] << " ";
                else
                    os << " " << f.numbers[row / 6][col / 6];

                col += 4;
            } else {
                os << " ";
            }
        }
        os << std::endl;
    }
    return os;
}

size_t field::get_score() const {
    return score;
}
