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
                    player.setCharacterStats(tools.stat_generator());
                    player.setStatModifiers(player.getCharacterStats());

                    player.displayStats();
                    
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
                        player.setCharacterClass(classMenuChoice, player.getStatModifiers());
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
