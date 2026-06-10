#include <iostream>

int main() 
{
    int x1{};
    std::cout << "Enter an integer: ";
    std::cin >> x1;

    int x2{};
    std::cout << "Enter another integer: ";
    std::cin >> x2;

    std::cout << x1 << " + " << x2 << " is " << x1 + x2 << ".\n";
    std::cout << x1 << " - " << x2 << " is " << x1 - x2 << ".\n";

    return 0;
}