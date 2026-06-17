#include <iostream>

double getDouble() 
{
    std::cout << "Enter a double value: ";
    double x{};
    std::cin >> x;
    return x;
}

char getOperator()
{
    std::cout << "Enter +, -, *, or /: ";
    char o{};
    std::cin >> o;
    return o;
}

int main() 
{
    double value1 { getDouble() };
    double value2 { getDouble() };
    char o { getOperator() };

    double result{};

    if (o == '+')
        result = value1 + value2;
    else if (o == '-')
        result = value1 - value2;
    else if (o == '*')
        result = value1 * value2;
    else if (o == '/')
        result = value1 / value2;

    std::cout << value1 << " " << o << " " << value2 << " = " << result;

    return 0;
}