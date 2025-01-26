#include <iostream>
#include "rcg_tools.hpp"
#include "character_sheet.hpp"


int main()
{

    //RCG_Tools tools;
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
                    /*player.setCharacterStats();*/
                    /*player.setStatModifiers();*/
                    /*player.setCharacterClass();*/
                    /*player.setCharacterRace();*/
                    player.setCharacterName();
                    std::cout << player.getCharacterName();

                    break;
                }
            case 2:
                isRunning = false;
                break;
        }
    }
    return 0;
}
