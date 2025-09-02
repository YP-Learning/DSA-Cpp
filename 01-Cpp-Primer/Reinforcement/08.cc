/*
# R-1.8 
Write a short C++ function, isMultiple, that takes two positive long values,
n and m, and returns true if and only if n is a multiple of m, that is, n = mi
for some integer i.
*/
#include <iostream>

bool isMultiple(long n, long m)
{
    return (n % m) == 0; // remainder is 0, so its a multiple
}

int main(const int argc, const char** argv)
{
    std::cout << "n = 7, m = 3 : " << isMultiple(7, 3) << "\nn = 8, m = 2 : " << isMultiple(8, 2) << std::endl;

    return (0);
}