#include <iostream>

class Ball 
{
private:
    std::string m_color { "black" };
    double m_radius { 10.0 };

public:
    Ball()
        : Ball{ "black", 10.0 }
    {
    }

    Ball(double radius)
        : Ball{ "black", radius }
    {
    }

    Ball(std::string color)
        : Ball{ color, 10.0 }
    {
    }

    Ball(std::string color, double radius)
        : m_color { color }
        , m_radius { radius }
    {
        std::cout << "Ball(" << color << ", " << radius << ")" << '\n';
    }
};

int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}