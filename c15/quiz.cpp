#include <iostream>
#include "Random.h"

class Monster
{
public:
    enum Type
    {
        dragon, 
        goblin, 
        ogre, 
        orc, 
        skeleton, 
        troll, 
        vampire, 
        zombie,
        maxMonsterTypes,
    };

private:
    Type m_type{};
    std::string m_name{"???"};
    std::string m_roar{"???"};
    int m_hitPoints{};

public:
    Monster(Type type, std::string name, std::string roar, int hitPoints)
    : m_type{type}, m_name{name}, m_roar{roar}, m_hitPoints{hitPoints}
    {}

    static constexpr std::string_view getTypeString(Type type)
    {
        switch (type) 
        {
            case dragon: return "dragon";
            case goblin: return "goblin";
            case ogre: return "ogre";
            case orc: return "orc";
            case skeleton: return "skeleton";
            case troll: return "troll";
            case vampire: return "vampire";
            case zombie: return "zombie";
            default: return "???";
        }
    }

    void print() const
    {   
        std::cout << m_name << " the " << getTypeString(m_type);

        if (m_hitPoints > 0)
            std::cout << " has " << m_hitPoints << " hit points and says " << m_roar << ".\n";
        else
            std::cout << " is dead.\n";
    }
};

namespace MonsterGenerator
{
    std::string getName(int num)
    {
        switch (num)
        {
            case 0: return "Tuff";
            case 1: return "ayo sus boi";
            case 2: return "Mr cool";
            case 3: return "Mr yoda";
            case 4: return "chud";
            case 5: return "number 5";
            default: return "???";
        }
    }

    // cspell:words ayoooooo ahhh boiiiii
    std::string getRoar(int num)
    {
        switch (num)
        {
            case 0: return "boo!";
            case 1: return "ayoooooo";
            case 2: return "boiiiii";
            case 3: return "*weird sounds*";
            case 4: return "ahhh! sorry I didn't mean to scare you. Anyways where were we? Oh yea, as I was saying";
            case 5: return "number 5";
            default: return "???";
        }
    }

    Monster generate()
    {
        return {static_cast<Monster::Type>(Random::get(0, Monster::Type::maxMonsterTypes-1)), 
            getName(Random::get(0,5)), 
            getRoar(Random::get(0,5)), 
            Random::get(-20, 100)};
    }
}

int main()
{
    Monster m{ MonsterGenerator::generate() };
	m.print();

    return 0;
}