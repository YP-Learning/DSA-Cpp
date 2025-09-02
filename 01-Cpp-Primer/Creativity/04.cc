/*
# C-1.4
Write a C++ function that takes an STL vector of int values and prints all
the odd values in the vector.
*/

#include <iostream>
#include <vector>

void printOdd(const std::vector<int> &vec)
{
    for (auto &element : vec)
    {
        if (element % 2 == 0)
            continue;
    
        std::cout << element << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    printOdd(vec);

    return 0;
}

