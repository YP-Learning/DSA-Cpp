/*
# C-1.7
Write a short C++ program that takes all the lines input to standard input
and writes them to standard output in reverse order. That is, each line is
output in the correct order, but the ordering of the lines is reversed.
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <unistd.h>
#include <signal.h>

bool gbStop = false;

void handlCtrlC(int signum)
{
    gbStop = true;
}

int main(int argc, char const *argv[])
{
    signal(SIGINT, handlCtrlC);

    std::vector<std::string> lines;
    std::string temp;

    while (!gbStop)
    {
        getline(std::cin, temp);
        lines.insert(lines.begin(), temp);
    }

    std::reverse(lines.begin(), lines.end());

    for (auto &line : lines)
    {
        std::cout << line << "\n";
    }

    return 0;
}

