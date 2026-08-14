#include <random>
#include <print>

struct AbilityScores
{
    int strength{};
    int dexterity{};
    int constitution{};
    int intelligence{};
    int wisdom{};
    int charisma{};
};

int roll_d6(std::mt19937& rng)
{
    std::uniform_int_distribution<int> dist(1, 6);
    return dist(rng);
}

int roll_3d6(std::mt19937& rng)
{
    return roll_d6(rng) + roll_d6(rng) + roll_d6(rng);
}

AbilityScores roll_ability_scores(std::mt19937& rng)
{
    AbilityScores ability_scores;
    ability_scores.strength = roll_3d6(rng);
    ability_scores.dexterity = roll_3d6(rng);
    ability_scores.constitution = roll_3d6(rng);
    ability_scores.intelligence = roll_3d6(rng);
    ability_scores.wisdom = roll_3d6(rng);
    ability_scores.charisma = roll_3d6(rng);
    return ability_scores;
}

int ability_modifier(int score)
{
    if (score <= 3)  return -3;
    if (score <= 5)  return -2;
    if (score <= 8)  return -1;
    if (score <= 12) return 0;
    if (score <= 15) return 1;
    if (score <= 17) return 2;
    return 3;
}

int main()
{
    std::random_device rd;
    std::mt19937 rng(rd());

    AbilityScores ability_scores{roll_ability_scores(rng)};

    std::println("Str: {}, mod: {}", ability_scores.strength, ability_modifier(ability_scores.strength));
    std::println("Dex: {}, mod: {}", ability_scores.dexterity, ability_modifier(ability_scores.dexterity));
    std::println("Con: {}, mod: {}", ability_scores.constitution, ability_modifier(ability_scores.constitution));
    std::println("Int: {}, mod: {}", ability_scores.intelligence, ability_modifier(ability_scores.intelligence));
    std::println("Wis: {}, mod: {}", ability_scores.wisdom, ability_modifier(ability_scores.wisdom));
    std::println("Cha: {}, mod: {}", ability_scores.charisma, ability_modifier(ability_scores.charisma));

    return 0;
}
