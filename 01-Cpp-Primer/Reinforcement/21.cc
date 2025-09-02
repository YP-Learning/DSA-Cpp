/*
# R-1.21
Write a short C++ function that takes an integer n and returns the sum of
all the odd integers smaller than n.
*/

#include <iostream>
#include <cstdlib>

long sumOddTillN(int n)
{
    long sum = 0;
    --n;
    if (n % 2 == 0)
        --n;

    while (n > 0)
    {
        sum += n--;
        n--;
    }

    return sum;
}

int main()
{
    std::cout << sumOddTillN(10) << std::endl;
    std::cout << sumOddTillN(200) << std::endl;
    std::cout << sumOddTillN(-10) << std::endl;

    return EXIT_SUCCESS;
}
