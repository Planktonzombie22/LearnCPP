#include <iostream>
#include <string_view>

int getAge(std::string_view name) 
{
    std::cout << "Enter the age of " << name << ": ";
    int age{};
    std::cin >> age;

    return age;

}

std::string getName(int number) 
{
    std::cout << "Enter the name of person #" << number << ": ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);

    return name;
}

void older(std::string_view name1, int age1, std::string_view name2, int age2) 
{   
    if (age1 > age2)
        std::cout << name1 << " (age " << age1 << ") is older than " << name2 << " (age " << age2 << ").\n";
    else
        std::cout << name2 << " (age " << age2 << ") is older than " << name1 << " (age " << age1 << ").\n";
}

int main() 
{
    std::string name1 { getName(1) };
    int age1 { getAge(name1) };

    std::string name2 { getName(2) };
    int age2 { getAge(name2) };

    older(name1, age1, name2, age2);

    return 0;
}