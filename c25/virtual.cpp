#include <iostream>
#include <vector>

//NOT DONE YET

class Point
{
private:
	int m_x{};
	int m_y{};

public:
	Point(int x, int y)
		: m_x{ x }, m_y{ y }
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		return out << "Point(" << p.m_x << ", " << p.m_y << ')';
	}
};

class Shape
{
public:
    virtual std::ostream& print(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, Shape& s) 
    {
        return s.print(out);
    }

    virtual ~Shape() = default;
};

class Circle : public Shape
{
private:
    Point m_center{ 0, 0 };
    int m_radius{};

public:
    Circle(const Point& center, int radius)
    : m_center{center}, m_radius{radius}
    {}

    virtual std::ostream& print(std::ostream& out) const override
    {
        return out << "Circle(" << m_center << ", radius " << m_radius << ")\n";
    }

    int getRadius() { return m_radius; }
};

class Triangle : public Shape
{
private:
    Point m_p1{ 0, 0 };
    Point m_p2{ 0, 0 };
    Point m_p3{ 0, 0 };

public:
    Triangle(const Point& p1, const Point& p2, const Point& p3)
    : m_p1{p1}, m_p2{p2}, m_p3{p3}
    {}

    virtual std::ostream& print(std::ostream& out) const override
    {
        return out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")\n";
    }
};

int getLargestRadius(const std::vector<Shape*>& v)
{
    int largest{};
    for (const auto& shape : v)
    {
        int value { dynamic_cast<Circle*>(shape)->getRadius() };
        largest = value > largest ? value : largest;
    }

    return largest;
}

int main()
{
    std::vector<Shape*> v{
	  new Circle{Point{ 1, 2 }, 7},
	  new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
	  new Circle{Point{ 7, 8 }, 3}
	};

	std::cout << v[0];
    std::cout << v[1];
    std::cout << v[2];

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	for (const auto& shape : v)
    {
        delete shape;
    } 

	return 0;
}