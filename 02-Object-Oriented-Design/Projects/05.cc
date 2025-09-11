/*
# P-2.5
Write a C++ program that has a Polygon interface that has abstract functions, 
area(), and perimeter(). Implement classes for Triangle, Quadrilateral, 
Pentagon, Hexagon, and Octagon, which implement this interface, 
with the obvious meanings for the area() and perimeter() functions.
Also implement classes, IsoscelesTriangle, EquilateralTriangle, Rectangle, 
and Square, which have the appropriate inheritance relationships. Finally, 
write a simple user interface that allows users to create polygons of
the various types, input their geometric dimensions, and then output their
area and perimeter. For extra effort, allow users to input polygons by specifying 
their vertex coordinates and be able to test if two such polygons are
similar.
*/
#include <iostream>
#include <cmath>

class Polygon
{
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
};

class Triangle : public Polygon
{
protected: 
    double a, b, c;
public:
    Triangle(double _a, double _b, double _c) : a(_a), b(_b), c(_c) { }
    double perimeter() 
    {
        return a + b + c;
    }

    double area()
    {
        double s = perimeter() / 2.0;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(double base, double side) : Triangle(base, side, side) {}
};

class EquilateralTriangle : public IsoscelesTriangle
{
public:
    EquilateralTriangle(double side) : IsoscelesTriangle(side, side) {}
};

class Quadrilateral : public Polygon
{
protected:
    double a, b, c, d;
public:
    Quadrilateral(double _a, double _b, double _c, double _d) : a(_a), b(_b), c(_c), d(_d) {}

    double perimeter()
    {
        return a + b + c + d;
    }
};

class Rectangle : public Quadrilateral
{
public: 
    Rectangle(double a, double b) : Quadrilateral(a, b, a, b) {}
    double area() 
    {
        return a * b;
    }
};

class Square : public Rectangle
{
public:
    Square(double s) : Rectangle(s, s) {}
};

int main(int argc, char const *argv[])
{
    Triangle t(3, 4, 5);
    std::cout << "Triangle area: " << t.area() << std::endl;
    std::cout << "Triangle perimeter: " << t.perimeter() << std::endl;

    IsoscelesTriangle it(5, 7);
    std::cout << "IsoscelesTriangle area: " << it.area() << std::endl;
    std::cout << "IsoscelesTriangle perimeter: " << it.perimeter() << std::endl;

    EquilateralTriangle et(6);
    std::cout << "EquilateralTriangle area: " << et.area() << std::endl;
    std::cout << "EquilateralTriangle perimeter: " << et.perimeter() << std::endl;

    Rectangle r(5, 10);
    std::cout << "Rectangle area: " << r.area() << std::endl;
    std::cout << "Rectangle perimeter: " << r.perimeter() << std::endl;

    Square s(7);
    std::cout << "Square area: " << s.area() << std::endl;
    std::cout << "Square perimeter: " << s.perimeter() << std::endl;
    
    return 0;
}

