#include <iostream>
#include "dice.hpp"


int main()
{

    Dice die;
    bool isRunning = true;
    while (isRunning)
    {
        std::cout << "What would you like to do\n";
        std::cout << "1. Roll\n";
        std::cout << "2. Quit\n";

        int choice{};
        std::cin >> choice;

        int temp{};

        switch (choice)
        {
            case 1:
                temp = die.roll(Dice::Sides::six, 3);
                std::cout << temp << "\n";
                break;
            case 2:
                isRunning = false;
                break;
        }
    }
    return 0;
}
