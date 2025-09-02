/*
# C-1.6
Write a short C++ program that outputs all possible strings formed by
using each of the characters ’a’, ’b’, ’c’, ’d’, ’e’, and ’f’ exactly
once.
*/

#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> permutations(std::vector<std::string> &vec)
{
    if (vec.size() == 1)
        return vec;
    
    std::vector<std::string> finalResult;

    for (int i = 0; i < vec.size(); i++)
    {
        std::vector copy = vec;
        copy.erase(copy.begin() + i);
        // abcdef (abcdef, abcdfe, abcedf, abcefd, abcfde, abcfed, ab..., ...)
        std::vector result = permutations(copy);

        finalResult.reserve(result.size());
        for (auto &ele : result)
            finalResult.push_back(vec[i] + ele); // 
    }

    return finalResult;
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> chars({"a", "b", "c", "d", "e", "f"});

    std::vector pers = permutations(chars);

    for (auto &ele : pers)
    {
        std::cout << ele << "\n";
    }

    std::cout << "Total No. Of Permutations : " << pers.size() << std::endl;

    return 0;
}

