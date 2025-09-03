/*
# R-17
Write a short program that takes as input three integers, a, b, and c, and
determines if they can be used in a correct arithmetic formula (in the given
order), like “a+b = c,” “a = b−c,” or “a ∗ b = c.”
*/

#include <iostream>

int main(int argc, char const *argv[])
{
    int a, b, c;

    std::cout << "Enter a b c: ";
    std::cin >> a >> b >> c;

    if ((a + b) == c)
        std::cout << "a + b = c" << std::endl;
    if (a == (b - c))
        std::cout << "a = b - c" << std::endl;
    if ((a * b) == c)
        std::cout << "a * b = c" << std::endl;
        
    return 0;
}
