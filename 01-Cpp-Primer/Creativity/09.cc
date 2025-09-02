/*
# C-1.9
Write a C++ class Vector2, that stores the (x,y) coordinates of a two-dimensional 
vector, where x and y are of type double. Show how to
override various C++ operators in order to implement the addition of two
vectors (producing a vector result), the multiplication of a scalar times
a vector (producing a vector result), and the dot product of two vectors
(producing a double result).
*/

#include <iostream>

class Vec2
{
private: 
    double x, y;
public:
    Vec2() : x(0), y(0) {}
    Vec2(double _x, double _y) : x(_x), y(_y) {}

    Vec2 operator+(const Vec2 &other)
    {
        return Vec2(this->x + other.x, this->y + other.y);
    }

    Vec2 operator*(const Vec2 &other)
    {
        return Vec2(this->x * other.x, this->y * other.y);
    }

    double dot(const Vec2 &other)
    {
        return (this->x * other.x) + (this->y * other.y);
    }

    friend std::ostream& operator<<(std::ostream &out, const Vec2 &vec)
    {
        out << "Vec2{x=" << vec.x << ", y=" << vec.y << "}";
        return out;
    }
};

int main(int argc, char const *argv[])
{
    Vec2 a(1, 2), b(3, 4);

    std::cout << a << "\n" << b << "\n" << a + b << "\n" << a * b << "\n" << a.dot(b) << std::endl;

    return 0;
}

