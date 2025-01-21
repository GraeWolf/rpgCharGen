#include "dice.hpp"
#include <iostream>

int Dice::roll(Sides dieType, int numberOfDie)
{
    int total{};
    switch (dieType)
    {
        case 1:
            for (int i{0}; i < numberOfDie; ++i)
            {
                    std::cout << Random::get(1, 3) << "\n";
            }
            break;
        case 2:
            for (int i{0}; i < numberOfDie; ++i)
            {
                    std::cout << Random::get(1, 4) << "\n";
            }
            break;
        case 3:
            for (int i{0}; i < numberOfDie; ++i)
            {
                int roll{Random::get(1, 6)};
                    std::cout << roll << "\t";
                    total += roll;
            }
            std::cout << "\n";
            break;
        case 4:
            for (int i{0}; i < numberOfDie; ++i)
            {
                    std::cout << Random::get(1, 8) << "\n";
            }
            break;
        case 5:
            for (int i{0}; i < numberOfDie; ++i)
            {
                    std::cout << Random::get(1, 10) << "\n";
            }
            break;
        case 6:
            for (int i{0}; i < numberOfDie; ++i)
            {
                    std::cout << Random::get(1, 12) << "\n";
            }
            break;
        case 7:
            for (int i{0}; i < numberOfDie; ++i)
            {
                    std::cout << Random::get(1, 20) << "\n";
            }
            break;
        case 8:
            for (int i{0}; i < numberOfDie; ++i)
            {
                    std::cout << Random::get(1, 100) << "\n";
            }
            break;

    }
    return total;
}
