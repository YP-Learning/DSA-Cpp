/*
# R-1.7 
Write a short C++ function that takes an integer n and returns the sum of
all the integers smaller than n.
*/
#include <iostream>

long long sumOfSmallerIntegers(int n)
{
    long long sum = 0;

    for (int i = n - 1; i > 0; i--)
        sum += i;

    return sum;
}

int main(const int argc, const char** argv)
{
    int i = 3242342;

    std::cout << " sum of integers smaller than " << i << " is " << sumOfSmallerIntegers(i) << std::endl;
    
    return (0);
}
