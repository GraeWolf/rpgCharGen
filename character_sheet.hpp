#ifndef CHARACTER_SHEET
#define CHARACTER_SHEET

#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include "rcg_tools.hpp"

class CharacterSheet: public RCG_Tools
{
private:
    std::vector<int> m_characterStats {};
    std::vector<int> m_savingThrows {};
    std::vector<int> m_statModifiers {0, 0, 0, 0, 0, 0};

    std::string m_characterName{};
    std::string m_characterClass{};
    std::string m_characterRace{};

    int m_characterLevel{1};
    int m_armorClass{};
    int m_hitPoints{};
    int m_attackBonus{};
    int m_money{};
public:
    void setCharacterStats();
    void setSavingThrows();
    void setStatModifiers();

    void setCharacterName();
    void setCharacterClass();
    void setCharacterRace();

    void setCharacterLevel();
    void setArmorClass();
    void setHitPoints();
    void setAttackBonus();
    void setMoney();

    std::vector<int> getStatModifiers();
    std::string getCharacterClass();
    std::vector<int> getCharacterStats();
    std::string getCharacterName();

    void displayStats();
    void confirmation(bool& choice);

};

#endif
