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
    std::cout << "stat size is " << stats.size() << "\n";
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

void CharacterSheet::setCharacterClass(std::string charClass)
{
    m_characterClass = charClass;
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

