#ifndef CHARACTER_SHEET
#define CHARACTER_SHEET

#include <vector>
#include <string>
#include <iostream>

class CharacterSheet
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
    void setCharacterStats(const std::vector<int>& stats);
    void setSavingThrows();
    void setStatModifiers(const std::vector<int>& stats);

    void setCharacterName(std::string name);
    void setCharacterClass();
    void setCharacterRace(std::string race);

    void setCharacterLevel();
    void setArmorClass();
    void setHitPoints();
    void setAttackBonus();
    void setMoney();

    std::vector<int> getStatModifiers();
    std::string getCharacterClass();
    std::vector<int> getCharacterStats();

    void displayStats();

};

#endif
