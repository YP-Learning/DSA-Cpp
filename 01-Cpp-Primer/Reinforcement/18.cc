/*
# R-1.18
Write a short C++ function, isMultiple, that takes two long values, n and
m, and returns true if and only if n is a multiple of m, that is, n = m · i for
some integer i.
*/

#include <iostream>
#include <cstdlib>

bool isMultiple(long n, long m)
{
    if ((n % m) == 0)
        return true;
    else
        return false;
}

int main(void)
{
    std::cout << isMultiple(10000000, 17000) << std::endl;
    std::cout << isMultiple(100000000, 1000000) << std::endl;
    return EXIT_SUCCESS;
}
