/*
# R-2.13
Give an example of a C++ code fragment that performs an array reference
that is possibly out of bounds, and if it is out of bounds, the program
catches that exception and prints an appropriate error message.
*/

#include <iostream>
#include <vector>
#include <stdexcept>

int main(int argc, char const *argv[])
{
    std::vector<int> arr = {1, 2, 3};

    try 
    {
        arr.at(4);
    } 
    catch (const std::out_of_range &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

