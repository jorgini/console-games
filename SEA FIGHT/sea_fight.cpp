#include "field.h"
#include <conio.h>
#include <ctime>

int main() {
    field user, bot;
    srand((time(NULL)));

    bool start = false;
    bool hard_mod = false;
    while (!start) {
        system("cls");
        std::cout << "\tChoose difficulty\n";
        if (!hard_mod) std::cout << "> ";
        else std::cout << "  ";
        std::cout << "Easy mod";
        if (hard_mod) std::cout << "\t> ";
        else std::cout << "\t  ";
        std::cout << "Hard mod";

        if (_kbhit()) {
            switch (_getch()) {
                case 'a' :
                    hard_mod = false;
                    break;
                case 'd' :
                    hard_mod = true;
                    break;
                case ' ' :
                    start = true;
                    break;
                default :
                    break;
            }
        }
    }


    bot.random_set();
    unsigned long long timer = clock();

    while (!user.check_ready()) {
        system("cls");

        std::cout<< "Put ships on the board!\n\n";
        if (_kbhit()) {
            switch (_getch()) {
                case 'a' :
                    user.get_cur_ship().move(ship::DIRECTION::LEFT);
                    break;
                case 'w' :
                    user.get_cur_ship().move(ship::DIRECTION::UP);
                    break;
                case 'd' :
                    user.get_cur_ship().move(ship::DIRECTION::RIGHT);
                    break;
                case 's' :
                    user.get_cur_ship().move(ship::DIRECTION::DOWN);
                    break;
                case ' ' :
                    user.put_ship();
                    break;
                case 'r' :
                    user.get_cur_ship().change_vertical();
                    break;
                case 'f' :
                    user.random_set();
                    break;
                default :
                    break;
            }
        }

        user.public_print();
        while(clock() - timer < 500) {}
    }

    bool turn = true;
    std::vector<std::pair<int, int>> diff = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int count = 0;
    std::pair<int, int> cur_diff = {0, 0};
    std::pair<int, int> prev1 = {-1, -1};
    std::pair<int, int> prev2 = {-1, -1};

    while(!user.check_game_over() && !bot.check_game_over()) {
        system("cls");
        std::cout << "Your board\n";
        user.public_print();
        std::cout << "\nOpponent's board\n";
        bot.private_print();

        if (turn) {
            std::cout << "\nEnter you shoot:";
            char a; int b;
            std::cin >> a >> b;
            if (a < 65 || a > 74 || b < 0 || b > 9) {
                std::cout << "\nWrong input\n";
                system("pause");
                continue;
            }
            int cor = bot.shoot({b, a - 65});
            if (cor == -1) {
                std::cout << "\nWrong input\n";
                system("pause");
                continue;
            }
            if (cor == 0)
                turn = false;
        }
        else {
            timer = clock();

            if (!hard_mod) {
                std::pair<int, int> random_shoot = {rand() % 10, rand() % 10};
                int cor = user.shoot(random_shoot);
                if (cor == -1 || cor == 1 || cor == 2)
                    continue;
                turn = true;
            }
            else {
                std::pair<int, int> random_shoot;
                if (std::pair<int, int>({-1, -1}) == prev2)
                    random_shoot = {rand() % 10, rand() % 10};
                else {
                    random_shoot = prev2;
                    count++;
                }
                int cor = user.shoot(random_shoot);
                if (cor == 0 || cor == -1) {
                    if (count == 1) {
                        prev2 = prev1 - cur_diff;
                        cur_diff = std::pair<int, int>({0, 0}) - cur_diff;
                        for (int i = 0; i < 3; i++) {
                            if (diff[i] == cur_diff) {
                                diff.erase(diff.begin() + i);
                                break;
                            }
                        }
                    }
                    else if (count > 1 && count < 4) {
                        int index = rand() % (4 - count);
                        prev2 = prev1 + diff[index];
                        cur_diff = diff[index];
                        diff.erase(diff.begin() + index);
                    }

                    if (cor == 0)
                        turn = true;
                }
                else if (cor == 1) {
                    if (std::pair<int, int>({-1, -1}) == prev1) {
                        prev1 = random_shoot;
                        int index = rand() % 4;
                        prev2 = prev1 + diff[index];
                        cur_diff = diff[index];
                        diff.erase(diff.begin() + index);
                        continue;
                    }
                    if (std::pair<int, int>({-1, -1}) != prev2) {
                        prev2 = prev2 + cur_diff;
                        count--;
                    }
                }
                if (cor == 2) {
                    diff = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                    prev1 = {-1, -1};
                    prev2 = {-1, -1};
                    cur_diff = {0, 0};
                    count = 0;
                    continue;
                }
            }

            while (clock() - timer < 1000) {}
        }
    }

    if (user.check_game_over())
        std::cout << "\n\tYou loss\n";
    else
        std::cout << "\n\tYou win\n";
    system("pause");

    return 0;
}