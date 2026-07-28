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
void print(const Triad<T>& t) {
    std::cout << '[' << t.v1 << ", " << t.v2 << ", " << t.v3 << ']';
}

int main() {
    Triad t1{1, 2, 3};
    Triad t2{1.2, 3.4, 5.6};
    print(t1);
    print(t2);
}
