/*
# R-2.16
Write a short C++ function that removes all the punctuation from a string s
storing a sentence. For example, this operation would transform the string
"Let’s try, Mike." to "Lets try Mike".
*/

#include <iostream>
#include <string>
#include <cstring>

int main(int argc, char const *argv[])
{
    std::string str = "Let's try, Mike.";
    std::string out = "";

    for (auto &ch : str)
    {
        if (isalnum(ch) || isblank(ch))
            out += ch;
    }

    std::cout << out << std::endl;

    return 0;
}

