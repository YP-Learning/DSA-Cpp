/*
# R-1.2 
Write a pseudo-code description of a method for finding the smallest and
largest numbers in an array of integers and compare that to a C++ function
that would do the same thing.

smallest <- ∞
largest <- -∞

for i <- 1 to A.length do
    if largest < A[i] then
        largest <- A[i]

    else if smallest > A[i] then
        smallest <- A[i]

*/
#include <iostream>
#include <cstdlib>
#include <climits>

void findSmallestLargest(int* array, const size_t& length, int& smallest, int& largest)
{
    smallest = INT_MAX;
    largest = INT_MIN;

    for (int i = 0; i < length; i++)
    {
        if (largest < array[i])
        {
            largest = array[i];
        }
        else if (smallest > array[i])
        {
            smallest = array[i];
        }
    }
}

int main(const int argc, const char** argv)
{
    int arr[] = { 72, 91, 71, 23, 12, 64, 32 };
    int smallest, largest;

    findSmallestLargest(arr, 7, smallest, largest);

    std::cout << "Smallest: " << smallest << "\nLargest: " << largest << std::endl;

    return (0);
}

