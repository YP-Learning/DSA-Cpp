/*
# C-2.4
Design a class Line that implements a line, which is represented by the formula 
y = ax+b. Your class should store a and b as double member variables. 
Write a member function intersect(ℓ) that returns the x coordinate
at which this line intersects line ℓ. If the two lines are parallel, then your
function should throw an exception Parallel. Write a C++ program that
creates a number of Line objects and tests each pair for intersection. Your
program should print an appropriate error message for parallel lines.
*/
#include <iostream>
#include <stdexcept>

class Line
{
private:
    double a, b;
public:
    class ParallelException : public std::exception { 
    public:
        virtual const char* what() const noexcept override
        {
            return "Lines Are Parallel, they do not meet at any point.";
        }
    };   

    Line() : a(0.0), b(0.0) {}
    Line(double slope, double intercept) : a(slope), b(intercept) {}
    double intersect(const Line &other) noexcept(false)
    {
        /*
            y = a1x + b1
            y = a2x + b2
            a1x + b1 = a2x + b2
            a1x = a2x + b1 - b2
            x(a1 - a2) = b1 - b2
            x = (b1 - b2) / (a1 - a2);
        */
        if (this->a == other.a)
            throw ParallelException();

        return (this->b - other.b) / (this->a - other.a);
    }
};

int main(int argc, char const *argv[])
{
    Line l1(3.14, 1.2), l2(3.14, 3.2), l3(6.18, 1.67);

    try
    {
        std::cout << l1.intersect(l2);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << l2.intersect(l3) << std::endl;

    return 0;
}

