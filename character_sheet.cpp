#include "character_sheet.hpp"

void CharacterSheet::setCharacterStats()
{
    m_characterStats = RCG_Tools::stat_generator();
}

void CharacterSheet::setSavingThrows()
{

}

void CharacterSheet::setStatModifiers()
{
    for (size_t i{}; i < m_characterStats.size(); ++i)
    {
        if (m_characterStats.at(i) == 18) {
            m_statModifiers.at(i) = 3;
        }
        else if (m_characterStats.at(i) > 15 && m_characterStats.at(i) < 18) {
            m_statModifiers.at(i) = 2;
        }
        else if (m_characterStats.at(i) > 12 && m_characterStats.at(i) < 16) {
            m_statModifiers.at(i) = 1;
        }
        else if (m_characterStats.at(i) > 8 && m_characterStats.at(i) < 13) {
            m_statModifiers.at(i) = 0;
        }
        else if (m_characterStats.at(i) > 5 && m_characterStats.at(i) < 9) {
            m_statModifiers.at(i) = -1; 
        }
        else if (m_characterStats.at(i) > 3 && m_characterStats.at(i) < 6) {
            m_statModifiers.at(i) = -2;    
        }
        else {
            m_statModifiers.at(i) = -3;            
        }
    }
}

void CharacterSheet::setCharacterName()
{
    bool choosingName = true;

    while (choosingName)
    {
        std::cout << "Please enter a name for your character. \n";
        std::string name{};
        std::getline(std::cin >> std::ws, name);
        CharacterSheet::confirmation(choosingName);
        m_characterName = name;
    }
}

void CharacterSheet::setCharacterClass()
{

    int classMenuChoice{};
    bool choosingClass = true;
    while (choosingClass)
    {
        displayStats();
        std::cout << "Please choose a class \n";
        std::cout << "1. Cleric\n";
        std::cout << "2. Fighter\n";
        std::cout << "3. Magic-User\n";
        std::cout << "4. Theif\n";

        std::cin >> classMenuChoice;
        
        switch (classMenuChoice)
        {
            case 1:
                if (m_characterStats.at(2) >= 9) {
                    std::cout << "You have chosen Cleric\n";
                    CharacterSheet::confirmation(choosingClass);

                    m_savingThrows = {11, 12, 14, 16, 15};

                    m_characterClass = "Cleric";
                }
                else {
                    std::cout << "Your Wisdom is not high enough for Cleric\n";
                    std::cout << "Please choose another class. \n";
                }
                break;
            case 2:
                if (m_characterStats.at(0) >= 9) {
                    std::cout << "You have chosen Fighter\n";
                    CharacterSheet::confirmation(choosingClass);

                    m_savingThrows = {12, 13, 14, 15, 17};

                    m_characterClass = "Fighter";
                }
                else {
                    std::cout << "Your Strength is not high enough for Fighter\n";
                    std::cout << "Please choose another class. \n";
                }
                break;
            case 3:
                if (m_characterStats.at(1) >=9) {
                    std::cout << "You have chosen Magic-User\n";
                    CharacterSheet::confirmation(choosingClass);

                    m_savingThrows = {13, 14, 13, 16, 15};

                    m_characterClass = "Magic-User";
                }
                else {
                    std::cout << "Your Intelligence is not high enough for Magic-User\n";
                    std::cout << "Please choose another class. \n";
                }
                break;
            case 4:
                if (m_characterStats.at(3) >= 9) {
                    std::cout << "You have chosen Theif\n";
                    CharacterSheet::confirmation(choosingClass);

                    m_savingThrows = {13, 14, 13, 16, 15};
                    m_characterClass = "Theif";
                }
                else {
                    std::cout << "Your Dexterity is not high enough for Theif\n";
                    std::cout << "Please choose another class. \n";
                }
                break;
            case 5:
               choosingClass = false;
                break;
        }
    }
    std::cout << "Your Class is " << m_characterClass << "\n";
    
}

void CharacterSheet::setCharacterRace()
{
    int raceMenuChoice{};
    bool choosingRace = true;
    while (choosingRace)
    {
        displayStats();
        std::cout << "Please choose a Race \n";
        std::cout << "1. Dwarf\n";
        std::cout << "2. Elf\n";
        std::cout << "3. Halfling\n";
        std::cout << "4. Human\n";

        std::cin >> raceMenuChoice;
        
        switch (raceMenuChoice)
        {
            case 1:
                if (m_characterStats.at(4) >= 9 && 
                    m_characterClass != "Magic-User" &&
                    m_characterStats.at(5) <= 17)
                {
                    std::cout << "You have chosen Dwarf\n";
                    CharacterSheet::confirmation(choosingRace);

                    m_savingThrows.at(0) -= 4;
                    m_savingThrows.at(1) -= 4;
                    m_savingThrows.at(2) -= 4;
                    m_savingThrows.at(3) -= 3;
                    m_savingThrows.at(4) -= 4;

                    m_characterRace = "Dwarf";
                }
                else {
                    std::cout << "You do not meet the qualifications to be a Dwarf.\n";
                    std::cout << "Please choose another race. \n";
                }
                break;
            case 2:
                if (m_characterStats.at(1) >= 9 &&
                    m_characterStats.at(4) <= 17)
                {
                    std::cout << "You have chosen Elf\n";
                    CharacterSheet::confirmation(choosingRace);

                    m_savingThrows.at(2) -= 1;
                    m_savingThrows.at(1) -= 2;
                    m_savingThrows.at(4) -= 2;

                    m_characterRace = "Elf";
                }
                else {
                    std::cout << "You do not meet the qualifications to be an Elf.\n";
                    std::cout << "Please choose another race. \n";
                }
                break;
            case 3:
                if (m_characterStats.at(3) >=9 &&
                    m_characterClass != "Magic-User" &&
                    m_characterStats.at(0) <= 17) 
                {
                    std::cout << "You have chosen Halfling\n";
                    CharacterSheet::confirmation(choosingRace);

                    m_savingThrows.at(0) -= 4;
                    m_savingThrows.at(1) -= 4;
                    m_savingThrows.at(2) -= 4;
                    m_savingThrows.at(3) -= 3;
                    m_savingThrows.at(4) -= 4;

                    m_characterRace = "Halfling";
                }
                else {
                    std::cout << "You do not meet the qualifications to be a Halfling.\n";
                    std::cout << "Please choose another race. \n";
                }
                break;
            case 4:
                std::cout << "You have chosen Human\n";
                CharacterSheet::confirmation(choosingRace);
                m_characterRace = "Human";
                break;
            case 5:
               choosingRace = false;
                break;
        }
    }
    std::cout << "Your Race is " << m_characterRace << "\n";

}

//int CharacterSheet::setCharacterLevel()
//{

//}
void CharacterSheet::setArmorClass()
{

}
void CharacterSheet::setHitPoints()
{
    if (m_characterClass == "Cleric")
    {
        m_hitPoints = RCG_Tools::roll(six) + m_statModifiers.at(4);
        if (m_hitPoints < 0)
            m_hitPoints = 1;
    }
    else if (m_characterClass == "Fighter")
    {
        m_hitPoints = RCG_Tools::roll(eight) + m_statModifiers.at(4);
        if (m_hitPoints < 0)
            m_hitPoints = 1;
    }
    else if (m_characterClass == "Magic-User")
    {
        m_hitPoints = RCG_Tools::roll(four) + m_statModifiers.at(4);
        if (m_hitPoints < 0)
            m_hitPoints = 1;
    }
    else if (m_characterClass == "Theif")
    {
        m_hitPoints = RCG_Tools::roll(four) + m_statModifiers.at(4);
        if (m_hitPoints < 0)
            m_hitPoints = 1;
    }
}
void CharacterSheet::setAttackBonus()
{

}

void CharacterSheet::setMoney()
{
    m_money = (RCG_Tools::roll(six) + RCG_Tools::roll(six) + RCG_Tools::roll(six)) * 10;
}

std::vector<int> CharacterSheet::getStatModifiers() 
{
    return {m_statModifiers.begin(), m_statModifiers.end()};
}

std::string CharacterSheet::getCharacterClass()
{
    return m_characterClass;
}

std::vector<int> CharacterSheet::getCharacterStats()
{
    return m_characterStats;
}

std::string CharacterSheet::getCharacterName()
{
    return m_characterName;
}

void CharacterSheet::displayStats()
{
    std::vector<std::string> statNames {"STR", "INT", "WIS", "DEX", "CON", "CHA"};

    for (size_t i{}; i < m_characterStats.size(); ++i)
    {
        std::cout << statNames.at(i) << "    " 
        << m_characterStats.at(i) << "    " << m_statModifiers.at(i) << "\n"; 
    } 

}

void CharacterSheet::confirmation(bool& choice)
{
    std::cout << "Are you sure\n";
    std::cout << "1. Yes\n";
    std::cout << "2. No\n";

    int confirmationChoice{};
    std::cin >> confirmationChoice;

    switch (confirmationChoice)
    {
        case 1:
            choice = false;
            break;
        case 2:
            break;
    }
}
