/*
# C-1.5
Write a C++ function that takes an array containing the set of all integers
in the range 1 to 52 and shuffles it into random order. Use the built-in function 
rand, which returns a pseudo-random integer each time it is called.
Your function should output each possible order with equal probability.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void shuffle (std::vector<int> &vec)
{
    srand(time(NULL)); 

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        int idx = rand() % vec.size();

        std::swap(vec[i], vec[idx]);
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> vec(52);

    for (int i = 1; i < 53; i++)
        vec[i - 1] = i;

    std::cout << "vector before: " ;
    for (auto &e : vec)
        std::cout << e << " ";
    std::cout << std::endl;

    shuffle(vec);

    std::cout << "vector after: " ;
    for (auto &e : vec)
        std::cout << e << " ";
    std::cout << std::endl;

    return 0;
}

