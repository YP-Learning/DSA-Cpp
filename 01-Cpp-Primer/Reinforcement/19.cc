/*
# R-1.19
Write a short C++ function, isTwoPower, that takes an int i and returns
true if and only if i is a power of 2. Do not use multiplication or division,
however.
*/

#include <iostream>
#include <cstdlib>

bool isTwoPower(int i)
{
    if (i < 0)
        return false;

    return ((i == 1) || (((i & 0b1) == 0b0) && isTwoPower(i >> 1)));
}

int main(void)
{
    std::cout << isTwoPower(1) << std::endl;
    std::cout << isTwoPower(2) << std::endl;
    std::cout << isTwoPower(4) << std::endl;
    std::cout << isTwoPower(128) << std::endl;
    std::cout << isTwoPower(7) << std::endl;
    std::cout << isTwoPower(123) << std::endl;
    std::cout << isTwoPower(126) << std::endl;

    return EXIT_SUCCESS;
}
