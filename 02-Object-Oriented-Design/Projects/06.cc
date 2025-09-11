/*
# P-2.6
Write a C++ program that inputs a document and then outputs a bar-chart
plot of the frequencies of each alphabet character that appears in that document
*/
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <climits>

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage : app.exe file.txt" << std::endl;
        return EXIT_FAILURE;
    }

    std::fstream fs(argv[1], std::ios::in);    
    std::string str;
    std::unordered_map<char, int> char_map;
    

    while (std::getline(fs, str))
    {
        for (auto &_ch: str)
        {
            char ch = toupper(_ch);
            if (char_map.find(ch) == char_map.end())
                char_map[ch] = 0;

            if (ch == ' ' || ch == '\t' || ch == '\n')
                continue;
            
            char_map[ch]++;
        }
    }

    int max = INT_MIN;

    for (auto val : char_map)
    {
        if (max < val.second)
            max = val.second;
    }


    std::cout << "Bar Chart : \n" << std::setprecision(3);
    for (auto val : char_map)
    {
        std::cout << val.first << " | " << std::string(((val.second * 100) / max), '#') << " " << val.second << "\n"; 
    }

    return 0;
}

