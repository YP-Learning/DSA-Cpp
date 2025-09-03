/*
# R-18
Write a short C++ program that creates a Pair class that can store two
objects declared as generic types. Demonstrate this program by creating
and printing Pair objects that contain five different kinds of pairs, such as
<int,string> and <float,long>.
*/

#include <iostream>

template<typename T, typename U>
class Pair
{
private:
    T first;
    U second;
public:
    Pair(T f, U s) : first(f), second(s) {}
    friend std::ostream& operator<<(std::ostream& os, Pair &p)
    {
        os << "Pair<" << p.first << ", " << p.second << ">\n";
        return os;
    }
};

int main(int argc, char const *argv[])
{
    Pair<int, int> p1(7, 9);
    Pair p2(7, 'e');
    Pair p3(3.14f, 'p');
    Pair p4(3.14f, 6.19f);
    Pair p5(true, "False");

    std::cout << p1 << p2 << p3 << p4 << p5;

    return 0;
}

