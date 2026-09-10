#include <iostream>
#include <cassert>

class IntArray
{
private:
    int* m_arr { nullptr };
    int m_length { 0 };

public:

    explicit IntArray(int length = 0)
    : m_length { length }
    {
        assert(length > 0 && "IntArray length should be a positive integer");
        m_arr = new int[static_cast<std::size_t>(m_length)] {};
    }

    IntArray(IntArray& arr)
    : m_length {arr.m_length}
    {
        m_arr = new int[static_cast<std::size_t>(m_length)] {};
        for (int i{}; i < m_length; ++i)
            m_arr[i] = arr.m_arr[i];
    }

    ~IntArray()
    {
        delete[] m_arr;
    }

    friend std::ostream& operator<<(std::ostream& out, IntArray& arr)
    {
        for (int i{}; i < arr.m_length; ++i)
            out << arr.m_arr[i] << ' ';

        return out; 
    }

    int& operator[](int index)
    {
        assert(index >= 0);
		assert(index < m_length);
        return m_arr[index];
    }
};

IntArray fillArray()
{
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
    
	IntArray a{ fillArray() };

	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	a[4] = 7;

	std::cout << b << '\n';

    return 0;
}