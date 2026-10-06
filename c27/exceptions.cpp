#include <iostream>

class Fraction
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    Fraction(int n, int d): m_numerator{n}, m_denominator{d} {}

    int getNum() const { return m_numerator; }
    int getDen() const { return m_denominator; }
    double getValue() const { return static_cast<double>(m_numerator) / m_denominator; }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    return out << "Fraction(" << f.m_numerator << ", " << f.m_denominator << ")\n";
}