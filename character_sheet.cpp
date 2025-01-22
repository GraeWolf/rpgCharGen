#include "character_sheet.hpp"

void CharacterSheet::setCharacterStats(std::vector<int>& stats)
{
    m_characterStats = stats;
}

void CharacterSheet::setSavingThrows()
{

}

void CharacterSheet::setStatModifiers(std::vector<int>& stats)
{
    for (size_t i{}; i < stats.size(); ++i)
    {
        if (stats.at(i) == 18) {
            m_statModifiers.at(i) = 3;
        }
        else if (stats.at(i) > 15 && stats.at(i) < 18) {
            m_statModifiers.at(i) = 2;
        }
        else if (stats.at(i) > 12 && stats.at(i) < 16) {
            m_statModifiers.at(i) = 1;
        }
        else if (stats.at(i) > 8 && stats.at(i) < 13) {
            m_statModifiers.at(i) = 0;
        }
        else if (stats.at(i) > 5 && stats.at(i) < 9) {
            m_statModifiers.at(i) = -1; 
        }
        else if (stats.at(i) > 3 && stats.at(i) < 6) {
            m_statModifiers.at(i) = -2;    
        }
        else {
            m_statModifiers.at(i) = -3;            
        }
    }
}

void CharacterSheet::setCharacterName(std::string name)
{
    m_characterName = name;
}

void CharacterSheet::setCharacterClass(int choice, std::vector<int>& stats)
{
    switch (choice)
    {
        case 1:
            if (stats.at(2) >= 9) {
                m_characterClass = "Cleric";
            }
            else {
                std::cout << "Your Wisdom is not high enough for Cleric\n";
            }
            break;
        case 2:
            if (stats.at(0) >= 9) {
               m_characterClass = "Fighter";
            }
            else {
                std::cout << "Your Strength is not high enough for Fighter\n";
            }
            break;
        case 3:
            if (stats.at(1) >=9) {
               m_characterClass = "Magic-User";
            }
            else {
                std::cout << "Your Intelligence is not high enough for Magic-User\n";
            }
            break;
        case 4:
            if (stats.at(3) >= 9) {
               m_characterClass = "Theif";
            }
            else {
                std::cout << "Your Dexterity is not high enough for Theif\n";
            }
            break;
    }
    
}

void CharacterSheet::setCharacterRace(std::string race)
{
    m_characterRace = race;
}

//int CharacterSheet::setCharacterLevel()
//{

//}
void CharacterSheet::setArmorClass()
{

}
void CharacterSheet::setHitPoints()
{

}
void CharacterSheet::setAttackBonus()
{

}

void CharacterSheet::setMoney()
{

}

std::vector<int> CharacterSheet::getStatModifiers() 
{
    return {m_statModifiers.begin(), m_statModifiers.end()};
}

std::string CharacterSheet::getCharacterClass()
{
    return m_characterClass;
}

