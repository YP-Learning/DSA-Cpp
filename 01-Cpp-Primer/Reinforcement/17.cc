/*
# R-1.17
Write a C++ class, AllKinds, that has three member variables of type int,
long, and float, respectively. Each class must include a constructor function 
that initializes each variable to a nonzero value, and each class should
include functions for setting the value of each type, getting the value of
each type, and computing and returning the sum of each possible combination of types.
*/
#include <cstdlib>
#include <iostream>

class AllKinds
{
private: 
    int ia;
    long la;
    float fa;
public:
    AllKinds() : ia(1), la(100), fa(123.45) {}
    AllKinds(int i, long l, float f) : ia(i), la(l), fa(f) {}

    int getInt() const
    {
        return ia;
    }

    long getLong() const
    {
        return la;
    }

    float getFloat() const
    {
        return fa;
    }

    void setInt(const int i)
    {
        ia = i;
    }

    void setLong(const long l)
    {
        la = l;
    }

    void setFloat(const float f)
    {
        fa = f;
    }
};

int main(void)
{
    AllKinds ak(12, 12345678, 876.54321);

    std::cout << ak.getInt() << std::endl;
    std::cout << ak.getLong() << std::endl;
    std::cout << ak.getFloat() << std::endl;

    ak.setFloat(123.456);

    std::cout << ak.getFloat() << std::endl;

    return EXIT_SUCCESS;
}
