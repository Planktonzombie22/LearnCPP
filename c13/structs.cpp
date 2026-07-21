#include <iostream>

struct Ads
{
    int watched {};
    double percentage {};
    double average_earning {};
};

std::ostream& operator<<(std::ostream& os, const Ads& ad)
{
    os << "How many ads were watched: " << ad.watched << '\n';
    os << "What percentage of users clicked on an ad: " << ad.percentage << '\n';
    os << "How many ads were watched: " << ad.average_earning << '\n';
    os << "Total revenue: " << ad.watched * ad.percentage * ad.average_earning << '\n';

    return os;
}

int main()
{
    std::cout << Ads {5, 0.5, 900};

    return 0;
}