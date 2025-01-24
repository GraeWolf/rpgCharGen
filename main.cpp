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
                    player.setStatModifiers(stats);
                    std::vector<std::string> statNames {"STR", "INT", "WIS", "DEX", "CON", "CHA"};

                    for (size_t i{}; i < stats.size(); ++i)
                    {
                        std::cout << statNames.at(i) << "    " 
                            << stats.at(i) << "    " << player.getStatModifiers().at(i) << "\n"; 
                    }
                    
                    int classMenuChoice{};
                    bool choosingClass = true;
                    while (choosingClass)
                    {
                        std::cout << "Please choose a class \n";
                        std::cout << "1. Cleric\n";
                        std::cout << "2. Fighter\n";
                        std::cout << "3. Magic-User\n";
                        std::cout << "4. Theif\n";
                        std::cout << "5. Finish Choosing.\n";

                        std::cin >> classMenuChoice;
                        if (classMenuChoice == 5)
                            choosingClass = false;
                        player.setCharacterClass(classMenuChoice, stats);
                    }

                    std::cout << "Your Class is " << player.getCharacterClass() << "\n";
                    break;
                }
            case 2:
                isRunning = false;
                break;
        }
    }
    return 0;
}
