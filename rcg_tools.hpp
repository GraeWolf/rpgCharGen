#ifndef RCG_TOOLS_H
#define RCG_TOOLS_H

#include "random_mt.hpp"
#include <vector>

class RCG_Tools 
{
private:
    // std::string m_dieType{};
    // int m_numberOfDie{};
public:
    enum Sides {three = 1, four, six, eight, ten, twelve, twenty, percentile};
    int roll(Sides dieType);
    std::vector<int> stat_generator();

    
};

#endif
