/*
# P-2.7
Write a C++ program that “makes change.” Your program should input
two numbers, one that is a monetary amount charged and the other that is
a monetary amount given. It should return the number of each kind of bill
and coin to give back as change for the difference between the amounts
given and charged. The values assigned to the bills and coins can be based
on the monetary system of any government. Try to design your program
so that it returns the fewest number of bills and coins as possible.
*/

#include <iostream>

enum Notes 
{
    NOTE2000    = 2000,
    NOTE500     = 500,
    NOTE200     = 200,
    NOTE100     = 100,
    NOTE50      = 50,
    NOTE20      = 20,
    NOTE10      = 10,
    COIN5       = 5,
    COIN2       = 2,
    COIN1       = 1,   
};

constexpr std::initializer_list<Notes> all_notes = { NOTE2000, NOTE500, NOTE200, NOTE100, NOTE50, NOTE20, NOTE10, COIN5, COIN2, COIN1 };

int main(int argc, char const *argv[])
{
    unsigned int charged, given, difference, n;

    std::cout << "Enter Charged Amount : ";
    std::cin >> charged;

    std::cout << "ENter Given Amount: ";
    std::cin >> given;

    if (given < charged)
    {
        std::cout << "Invalid Amounts Entered\n";
        return EXIT_FAILURE;
    }

    difference = given - charged;

    for (auto &note : all_notes)
    {
        n = difference / note;
        difference %= note;

        std::cout << ((note < 10) ? "COIN" : "NOTE") << " of " << note << "\t: " << n << "\n";
    }

    return 0;
}
