/*
# C-1.10
Write an efficient C++ function that takes any integer value i and returns
2^i , as a long value. Your function should not multiply 2 by itself i times;
there are much faster ways of computing 2^i.
*/

#include <iostream>

long twopower(int i)
{
    return 0b1 << i;
}

int main(int argc, char const *argv[])
{
    int i ;

    std::cout << "Enter i: ";
    std::cin >> i;

    std::cout << twopower(i) << "\n";

    return 0;
}

