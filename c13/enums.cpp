#include <iostream>

enum class Animals 
{
    pig, 
    chicken, 
    goat, 
    cat, 
    dog, 
    duck,
};

std::string_view getAnimalName(Animals animal) 
{
    switch (animal)
    {
        case Animals::pig: return "pig";
        case Animals::chicken: return "chicken";
        case Animals::goat: return "goat";
        case Animals::cat: return "cat";
        case Animals::dog: return "dog";
        case Animals::duck: return "duck";
        default: return "Unknown";
    }
}

void printNumberOfLegs(Animals animal)
{
    int legs {};

    switch (animal)
    {
        case Animals::pig: 
        case Animals::goat:
        case Animals::cat:
        case Animals::dog:
            legs = 4;
            break;
        case Animals::chicken:
        case Animals::duck: 
            legs = 2;
            break;
        default: legs = -1;
    }

    std::cout << "A " << getAnimalName(animal) << " has " << legs << " legs.\n";
}

int main()
{
    printNumberOfLegs(Animals::cat);
    printNumberOfLegs(Animals::chicken);

    return 0;
}