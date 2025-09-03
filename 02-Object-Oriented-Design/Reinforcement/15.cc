/*
# R-2.15
Write a short C++ function that counts the number of vowels in a given
character string
*/

#include <iostream>
#include <string>

int countVowels(const std::string &str)
{
    int counter = 0;

    for (auto &ch : str)
    {
        switch (ch)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                counter++;
                break;
            default:
                break;
        }
    }

    return counter;
}

int main(int argc, char const *argv[])
{
    std::string str = "Hello Goodrich!";

    std::cout << countVowels(str) << std::endl;
    return 0;
}

