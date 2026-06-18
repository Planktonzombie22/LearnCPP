#include <iostream>

float calculateFall(int height, int seconds) 
{
    float distance { seconds * seconds * 9.8 / 2.0 };
    float fall { height - distance };

    if (fall < 0)
        fall = 0.0;

    return fall;
}

void printHeight(int height, int seconds) 
{
    float fall { calculateFall(height, seconds) };
    if (fall)
        std::cout << "At " << seconds << " seconds, the ball is at height: " << fall << " meters" << '\n';
    else
        std::cout << "At " << seconds << " the ball is on the ground." << '\n';
}

int main() 
{
    std::cout << "Enter the height of the tower in meters: ";
    int height{};
    std::cin >> height;

    printHeight(height, 0);
    printHeight(height, 1);
    printHeight(height, 2);
    printHeight(height, 3);
    printHeight(height, 4);
    printHeight(height, 5);

    return 0;
}