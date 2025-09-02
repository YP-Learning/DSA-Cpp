/*
# R-1.9 
Write a C++ function printArray(A, m, n) that prints an m × n 
two-dimensional array A of integers, declared to be “int** A,” to the 
standard output. Each of the m rows should appear on a separate line.
*/
#include <iostream>

void printArray(int** A, size_t m, size_t n)
{
    for ( size_t i = 0; i < m; i++ )
    {
        for ( size_t j = 0; j < n; j++ )
            std::cout << A[i][j] << " ";
    
        std::cout << "\n";
    }
}

int main(const int argc, const char** argv)
{
    int** A = new int*[4];

    for (int i = 0; i < 4; i++)
        A[i] = new int[3]{ i, i + 1, i + 2 };

    printArray(A, 4, 3);

    return (0);
}
