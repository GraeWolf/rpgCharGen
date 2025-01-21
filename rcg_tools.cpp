#include "rcg_tools.hpp"

int RCG_Tools::roll(Sides dieType)
{
    int rolled_number{};
    switch (dieType)
    {
        case 1:
            rolled_number = Random::get(1, 3);
            break;
        case 2:
            rolled_number = Random::get(1, 4);
            break;
        case 3:
            rolled_number = Random::get(1, 6);
            break;
        case 4:
            rolled_number = Random::get(1, 8);
            break;
        case 5:
            rolled_number = Random::get(1, 10);
            break;
        case 6:
            rolled_number = Random::get(1, 12);
            break;
        case 7:
            rolled_number = Random::get(1, 20);
            break;
        case 8:
            rolled_number = Random::get(1, 100);
            break;

    }
    return rolled_number;
}

std::vector<int> RCG_Tools::stat_generator()
{
    int total{};
    std::vector<int> stats {};
    for (size_t i{}; i < 6; ++i)
    {
        total = RCG_Tools::roll(six) + RCG_Tools::roll(six) + RCG_Tools::roll(six);
        stats.push_back(total);
    }
    return stats;
}
