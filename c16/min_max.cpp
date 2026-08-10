#include <iostream>
#include <utility>
#include <vector>

template <typename T>
std::pair<std::size_t, std::size_t> min_max(const std::vector<T>& arr)
{
    std::size_t i_max {};
    std::size_t i_min {};
    
    for (std::size_t i {}; i < std::size(arr); ++i)
    {
        if (arr[i_max] < arr[i])
            i_max = i;
        if (arr[i_min] > arr[i])
            i_min = i;
    }

    return { i_min, i_max };
}

template <typename T>
void printVector(const std::vector<T>& arr)
{
    std::cout << "With array ( ";
    bool comma { false };
    for (const T& val : arr)
    {
        if (comma)
            std::cout << ", ";
        
        std::cout << val;
        comma = true;
    }
    std::cout << "):\n";
}

template <typename T>
void printMinMax(const std::vector<T>& arr)
{
    printVector(arr);
    std::pair<std::size_t, std::size_t> mm { min_max(arr) };

    std::cout << "The min element has index " << mm.first << " and value " << arr[mm.first] << '\n';
    std::cout << "The max element has index " << mm.second << " and value " << arr[mm.second] << '\n';
}

int main()
{
    std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
    std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };

    printMinMax(v1);
    printMinMax(v2);

    return 0;
}