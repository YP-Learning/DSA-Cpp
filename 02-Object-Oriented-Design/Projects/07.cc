/*
# P-2.7
Write a C++ program that inputs a list of words separated by whitespace,
and outputs how many times each word appears in the list. You need not
worry about efficiency at this point, however, as this topic is something
that will be addressed later in this book.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

int main(int argc, char const *argv[])
{
    std::string line, word;
    std::unordered_map<std::string, int> words;
    std::cout << "Enter words separated by space: ";

    getline(std::cin, line);

    std::stringstream ss(line);

    while(getline(ss, word, ' '))
    {
        if (words.find(word) == words.end())
            words[word] = 0;

        words[word]++;
    }

    for(auto &word : words)
    {
        std::cout << word.first << " : " << word.second << "\n";
    }
    
    return 0;
}

