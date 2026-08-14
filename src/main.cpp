#include <random>
#include <print>

int roll_d6(std::mt19937& rng)
{
    std::uniform_int_distribution<int> dist(1, 6);
    return dist(rng);
}

int roll_3d6(std::mt19937& rng)
{
    std::uniform_int_distribution<int> dist(1,6);
    return roll_d6(rng) + roll_d6(rng) + roll_d6(rng);
}

int main()
{
    std::random_device rd;
    std::mt19937 rng(rd());

    std::println("1: {}", roll_d6(rng));
    std::println("3d6: {}", roll_3d6(rng));
    std::println("3d6: {}", roll_3d6(rng));
    return 0;
}
