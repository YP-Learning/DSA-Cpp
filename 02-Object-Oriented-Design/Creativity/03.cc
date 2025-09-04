/*
# C-2.3
Most modern C++ compilers have optimizers that can detect simple cases
when it is logically impossible for certain statements in a program to ever
be executed. In such cases, the compiler warns the programmer about the
useless code. Write a short C++ function that contains code for which it
is provably impossible for that code to ever be executed, but your favorite
C++ compiler does not detect this fact.
*/
#include <iostream>

void myFunc(const int &i)
{
    if (i < 0)
        std::cout << "Negative no.\n";
    else if (i % 2 == 0)
        std::cout << "Even no.\n";
    else if (i % 2 == 1)
        std::cout << "Odd no.\n";
    else if (i == 0)
        std::cout << "Zero.\n";
}

int main(int argc, char const *argv[])
{
    int i; 

    std::cout << "Enter an Integer: ";
    std::cin >> i;

    myFunc(i);

    return 0;
}

