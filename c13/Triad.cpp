#include <iostream>

template <typename T>
struct Triad {
    T v1 {};
    T v2 {};
    T v3 {};
};

template <typename T>
Triad(T, T, T) -> Triad<T>;

template <typename T>
void print(Triad<T>& t) 
{
    std::cout << '[' << t.v1 << ", " << t.v2 << ", " << t.v3 << ']';
}

int main()
{
	Triad t1{ 1, 2, 3 }; // note: uses CTAD to deduce template arguments
	print(t1);

	Triad t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
	print(t2);

	return 0;
}