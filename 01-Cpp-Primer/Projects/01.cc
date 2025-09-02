/*
# P-1.1
A common punishment for school children is to write out the same sentence 
multiple times. Write a C++ stand-alone program that will write
out the following sentence one hundred times: “I will always use object
oriented design.” Your program should number each of the sentences and
it should “accidentally” make eight different random-looking typos at 
various points in the listing, so that it looks like a human typed it all by hand.
*/

#include <iostream>
#include <string>
#include <ctime>

int main(int argc, char const *argv[])
{
    std::string line;

    std::cout << "Enter the Line: ";
    getline(std::cin, line);

    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        if ((rand() % 100) < 8)
        {
            std::string copy = line;

            int idx = rand() % (line.size() - 1);
            if ((rand() % 100) < 50)
            {
                // swap 2 consecutive chars
                std::swap(copy[idx], copy[idx + 1]);
            }
            else 
            {
                copy[idx] = (rand() % 26) + 'a';
            }

            std::cout << "[" << i + 1 << "] " << copy << "\n";
        }
        else 
            std::cout << "[" << i + 1 << "] " << line << "\n";
    }

    return 0;
}

