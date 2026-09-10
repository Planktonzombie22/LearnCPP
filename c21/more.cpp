#include <iostream>
#include <cstdint>

class Average
{
private:
    std::int32_t m_total{};
    int length{};

public:

    Average& operator+=(std::int32_t value)
    {
        m_total += value;
        ++length;

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, Average& avg);
};

std::ostream& operator<<(std::ostream& out, Average& avg)
{
    if (avg.length == 0)
        return out << 0;

    out << (static_cast<double>(avg.m_total) / avg.length);
    
    return out;
}

int main()
{
    Average avg{};
	std::cout << avg << '\n';

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}