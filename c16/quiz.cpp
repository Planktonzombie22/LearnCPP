#include <iostream>
#include <vector>
#include <cassert>

namespace Items
{
    enum Type : int
    {
        health_potion,
        torches,
        arrows,
        max_items,
    };
}

template <typename T>
constexpr std::size_t toUZ(T value)
{
    static_assert(std::is_integral<T>() || std::is_enum<T>());

    return static_cast<std::size_t>(value);
}

int countTotalItems(const std::vector<int>& player)
{
    int total {};
    for (auto count : player)
        total += count;
    return total;
}

std::string_view getItemNameSingular(Items::Type item)
{
    switch (item) 
    {
        case Items::health_potion: return "health_potion";
        case Items::torches: return "torch";
        case Items::arrows: return "arrow";

        default: return "???";
    }
}

std::string_view getItemNamePlural(Items::Type item)
{
    switch (item) 
    {
        case Items::health_potion: return "health_potions";
        case Items::torches: return "torches";
        case Items::arrows: return "arrows";

        default: return "???";
    }
}

void printItems(const std::vector<int>& player)
{
    for (int item {}; item < Items::max_items; ++item)
    {
        bool plural { player[toUZ(item)] != 1 };
        Items::Type item_type { static_cast<Items::Type>(item) };
        std::cout << "You have " << player[toUZ(item)] << " " << (plural ? getItemNamePlural(item_type) : getItemNameSingular(item_type)) << '\n';
    }
}

int main()
{
    std::vector player { 1, 5, 10 };
    assert(Items::max_items == std::size(player) && "player does not match items");

    printItems(player);
    std::cout << "You have " << countTotalItems(player) << " total items\n";

    return 0;
}