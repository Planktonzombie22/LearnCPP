#include <iostream>

namespace ops
{
    template <typename T>
    T max(T i, T j)
    {
        if (i > j)
            return i;
            
        return j;   
    }

    template <typename T>
    void swap(T& i, T& j)
    {
        T copy { i };
        i = j;
        j = copy;
    }

    template <typename T>
    T& getLargestElement(T* arr, int length)
    {
        T* largest { arr };
        for (int i { 1 }; i < length; ++i)
        {
            if (arr[i] > *largest)
                largest = &arr[i];
        }

        return *largest;
    }
}

int main()
{
    int arr[] {1, 2, -5, 7, 20, 11};
    std::cout << ops::getLargestElement(arr, 6);

    return 0;
}