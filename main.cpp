#include <iostream>
#include "rcg_tools.hpp"
#include "character_sheet.hpp"


int main()
{

    RCG_Tools tools;
    CharacterSheet player;
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
                {
                    std::vector<int> stats {tools.stat_generator()};
                    for (size_t i{}; i < 6; ++i)
                    {
                        std::cout << stats.at(i) << "\n";
                    }
                    player.setStatModifiers(stats);
                    for (size_t i{}; i < stats.size(); ++i)
                    {
                        std::cout << player.getStatModifiers().at(i) << "\n"; 
                    }
                    break;
                }
            case 2:
                isRunning = false;
                break;
        }
    }
    return 0;
}
