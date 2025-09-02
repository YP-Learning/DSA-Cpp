/*
# R-1.3 
Give a C++ definition of a struct called Pair that consists of two members. 
The first is an integer called first, and the second is a double called
second.
*/
#include <iostream>

struct Pair {
    int first;
    double second;
};

int main(int argc, const char** argv)
{
    struct Pair p1 = { 7, 3.14 };

    std::cout << "first: " << p1.first << " \nSecond:" << p1.second << std::endl;

    return (0);
}
