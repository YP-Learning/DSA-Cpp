/*
# C-1.2
Write a short C++ function that takes an array of int values and determines
if there is a pair of numbers in the array whose product is even.
*/

#include <iostream>

int main(int argc, char const *argv[])
{
    int A[7] = {1, 3, 5, 7, 9, 8, 2};

    bool found = false;
    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 7; j++) {
            if ((A[i] * A[j]) % 2 == 0) {
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (found) {
        std::cout << "Found a pair with an even product." << std::endl;
    } else {
        std::cout << "No pair found with an even product." << std::endl;
    }

    return 0;
}
