#ifndef DICE_H
#define DICE_H

#include "random_mt.hpp"

class Dice 
{
private:
    // std::string m_dieType{};
    // int m_numberOfDie{};
public:
    enum Sides {three = 1, four, six, eight, ten, twelve, twenty, percentile};
    int roll(Sides dieType, int numberOfDie);
    
};

#endif
