#include "field2048.h"
#include <iostream>
#include <conio.h>

int main() {
    size_t size;
    std::cout << "Enter size of field\n";
    std::cin >> size;

    field f(size);

    while(true) {
        if (_kbhit()) {

            int flag;
            switch (_getch()) {
                case 'a' :
                    flag = f.push(LEFT);
                    break;
                case 'w' :
                    flag = f.push(UP);
                    break;
                case 'd' :
                    flag = f.push(RIGHT);
                    break;
                case 's' :
                    flag = f.push(DOWN);
                    break;
                default :
                    break;
            }
            if (flag == CORRECT) {
                system("cls");
                std::cout << f;
                std::cout << "\nYou score: " << f.get_score();
            }
            if (flag == END) {
                std::cout << "\nEnd of game\n";
                std::cin >> flag;
                break;
            }
        }
    }
}