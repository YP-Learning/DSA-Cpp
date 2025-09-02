/*
# C-1.8
Write a short C++ program that takes two arguments of type STL vector<double>, 
a and b, and returns the element-by-element product of a
and b. That is, it returns a vector c of the same length such that c[i] =
a[i] · b[i].
*/

#include <vector>
#include <iostream>

std::vector<double> multiply(const std::vector<double> a, const std::vector<double> b)
{
    if (a.size() != b.size())
        return {};

    std::vector<double> c(a.size());

    for (int i = a.size() - 1; i >= 0; i--)
        c[i] = a[i] * b[i];

    return c;
}

int main(int argc, char const *argv[])
{
    std::vector a = {1.2, 2.3, 3.4, 4.5};
    std::vector b = {5.6, 6.7, 7.8, 8.9};

    std::vector c = multiply(a, b);

    std::cout << "a: ";
    for (auto &e : a)
        std::cout << e << " ";
    std::cout << std::endl;

    std::cout << "b: ";
    for (auto &e : b)
        std::cout << e << " ";
    std::cout << std::endl;

    std::cout << "c: ";
    for (auto &e : c)
        std::cout << e << " ";
    std::cout << std::endl;

    return 0;
}

