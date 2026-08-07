#include <iostream>
#include <limits>
#include <cassert>
#include <vector>

namespace Fizzbuzz
{
    std::vector<std::string_view> sounds {"fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};
    std::vector<int> divisors {3, 5, 7, 11, 13, 17, 19};
}

template <typename T>
void printArray(const std::vector<T>& arr)
{
    for (std::size_t index { 0 }; index < arr.size(); ++index)
        std::cout << arr[index] << ' ';

    std::cout << '\n';
}

template <typename T>
T findMax(const std::vector<T>& arr)
{
    if (arr.size() < 1)
        return T{};

    T max { arr[0] };
    for (std::size_t index { 1 }; index < arr.size(); ++index)
    {
        if (max < arr[index])
            max = arr[index];
    }

    return max;
}


template <typename T>
int findIndex(const std::vector<T>& arr, int num)
{
    for (std::size_t index { 0 }; index < arr.size(); ++index)
    {
        if (arr[index] == num)
            return static_cast<int>(index);
    }

    return -1;
}

template <typename T>
T getValidNumber(std::string_view prompt, T low, T high)
{
    T val {};
    do
    {
        std::cout << prompt;
        std::cin >> val;
        if (!std::cin)
            std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (val < low || val > high);

    return val;
}

// cspell:words fizzbuzz
void fizzbuzz(const std::vector<int>& divisors, const std::vector<std::string_view>& sounds, int ncount)
{
    assert(std::size(divisors) == std::size(sounds) && "fizzbuzz: array sizes don't match");

    for (int count { 1 }; count <= ncount; ++count)
    {
        bool printed { false };

        for (std::size_t index { 0 }; index < divisors.size(); ++index)
        {
            if (count % divisors[index] == 0)
            {
                std::cout << sounds[index];
                printed = true;
            }
        }

        if (!printed)
            std::cout << count;

        std::cout << '\n';
    }
}

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    auto num { getValidNumber("Enter a number between 1 and 9: ", 1.0, 9.0) };
    printArray(arr);
    int index { findIndex(arr, num) };

    if (index == -1)
        std::cout << "The number " << num << " was not found\n";
    else
        std::cout << "The number " << num << " has index " << index << '\n';

    std::vector data1 { 84, 92, 76, 81, 56 };
    std::cout << findMax(data1) << '\n';

    std::vector data2 { -13.0, -26.7, -105.5, -14.8 };
    std::cout << findMax(data2) << '\n';

    std::vector<int> data3 { };
    std::cout << findMax(data3) << '\n';

    int count{};
    std::cout << "How many u want? ";
    std::cin >> count;

    fizzbuzz(Fizzbuzz::divisors, Fizzbuzz::sounds, count);

    return 0;
}