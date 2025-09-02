/*
# R-1.22
Write a short C++ function that takes a positive double value x and returns
the number of times we can divide x by 2 before we get a number less
than 2.
*/

#include <iostream>
#include <cstdlib>

int canDivideBy2n(double x)
{
    int i = 0;

    while (x > 2)
    {
        x /= 2;
        i++;
    }

    return i;
}

int main()
{
    std::cout << canDivideBy2n(200.0) << std::endl;
    std::cout << canDivideBy2n(2123.0) << std::endl;
    std::cout << canDivideBy2n(2.0) << std::endl;
    std::cout << canDivideBy2n(200000000000.0) << std::endl;

    return EXIT_SUCCESS;
}
