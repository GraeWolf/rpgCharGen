#include <iostream>
#include "rcg_tools.hpp"


int main()
{

    RCG_Tools tools;
    bool isRunning = true;
    while (isRunning)
    {
        std::cout << "What would you like to do\n";
        std::cout << "1. Roll\n";
        std::cout << "2. Quit\n";

        int choice{};
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                std::cout << tools.roll(RCG_Tools::Sides::six) << "\n";
                break;
            case 2:
                isRunning = false;
                break;
        }
    }
    return 0;
}
