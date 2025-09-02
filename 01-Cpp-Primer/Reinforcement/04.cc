/*
# R-1.4 
What are the contents of string s after executing the following statements.
    string s = "abc";
    string t = "cde";
    s += s + t[1] + s;

Guess: "abcabcdabc"
*/
#include <iostream>
#include <string>
using std::string;

int main(int argc, const char** argv)
{
    string s = "abc";
    string t = "cde";
    s += s + t[1] + s;

    std::cout << s << std::endl;

    return (0);
}
