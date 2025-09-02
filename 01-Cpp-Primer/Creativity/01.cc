/*
# C-1.1
Write a pseudo-code description of a method that reverses an array of n
integers, so that the numbers are listed in the opposite order than they were
before, and compare this method to an equivalent C++ method for doing
the same thing.

A = [...]

for i <- 1 to A.length / 2
    swap(A[i], A[A.length - i])
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>

int main(void)
{
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    
    for (int i = 0; i < 10; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;

    for (int i = 0; i < (10 / 2); i++)
        std::swap(A[i], A[10 - i - 1]);

    for (int i = 0; i < 10; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
