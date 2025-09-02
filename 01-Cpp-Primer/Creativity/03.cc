/*
# C-1.3
Write a C++ function that takes an STL vector of int values and 
determines if all the numbers are different from each other (that is, they are
distinct).
*/

#include <iostream>
#include <vector>
#include <unordered_set>

bool allDistinct(const std::vector<int>& vec) {
    std::unordered_set<int> seen;
    for (int num : vec) {
        if (seen.count(num)) {
            return false;  // Found a duplicate
        }
        seen.insert(num);
    }
    return true;  // All numbers are distinct
}

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {1, 2, 2, 4, 5};

    std::cout << "vec1 is " << (allDistinct(vec1) ? "distinct" : "not distinct") << std::endl;
    std::cout << "vec2 is " << (allDistinct(vec2) ? "distinct" : "not distinct") << std::endl;

    return 0;
}
