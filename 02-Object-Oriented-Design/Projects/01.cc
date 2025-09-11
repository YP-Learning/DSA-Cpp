/*
# p-2.1 Write a C++ program that can take a positive integer greater than 2 as
input and write out the number of times one must repeatedly divide this
number by 2 before getting a value less than 2.
*/
#include <iostream>

int main(int argc, char const *argv[])
{
    int num, nDivide = 0;
    
    // 10101
    // 10101 -> 1010 -> 101 -> 10 -> 1
    // 21 -> 10 -> 5 > 2 > 1
    // 11111
    std::cout << "Enter a number greater than 2 : ";
    std::cin >> num;

    if (num < 2)
    {
        std::cout << "The Entered no is not greater than 2" << std::endl;
        return EXIT_FAILURE;
    }

    while (!(num < 2))
    {
        num >>= 1; // same as num /= 2
        nDivide++;
    }    

    std::cout << "The Entered no can be repeatedly divided by 2 : " << nDivide << " times\n";

    return 0;
}

