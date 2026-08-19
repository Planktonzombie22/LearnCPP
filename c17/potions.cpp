#include <iostream>
#include <array>
#include <string_view>
#include "Random.h"

namespace Potion
{
    enum Type
    {
        healing,
        mana,
        speed,
        invisibility,
        max_potions,
    };

    constexpr std::array types { healing, mana, speed, invisibility };
    constexpr std::array<std::string_view, 4> names { "healing", "mana", "speed", "invisibility" };
    constexpr std::array prices { 20, 30, 12, 50 };

    static_assert(std::size(types) == max_potions); 
    static_assert(std::size(prices) == max_potions);
    static_assert(std::size(names) == max_potions);
}

void shop() 
{
    std::cout << "Here is our selection for today:\n";

    for (auto p : Potion::types)
        std::cout << p << ") " << Potion::names[p] << " costs " << Potion::prices[p] << '\n';
}

class Player
{
private:
    static constexpr int s_minStartingGold { 80 };
    static constexpr int s_maxStartingGold { 120 };

    std::array<Potion::Type, Potion::max_potions> m_inventory {};
    int m_gold { Random::get(s_minStartingGold, s_maxStartingGold) };
    std::string m_name {};

public:
    void getName() 
    {
        std::cout << "Enter your name: ";
         std::getline(std::cin >> std::ws, m_name);
        std::cout << "Hello, " << m_name << ", you have " << m_gold << " gold.";
    }
};

int main()
{
    std::cout << "Welcome to Roscoe's potion emporium!\n";

    Player player {};
    player.getName();
    std::cout << "\n\n";
    shop();

     std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";
}