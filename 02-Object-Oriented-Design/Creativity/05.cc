/*
# C-2.5
Write a C++ class that is derived from the Progression class to produce a
progression where each value is the absolute value of the difference between 
the previous two values. You should include a default constructor
that starts with 2 and 200 as the first two values and a parametric constructor 
that starts with a specified pair of numbers as the first two values
*/
#include <iostream>
#include <cmath>

class Progression { // a generic progression
    public:
        Progression(long f = 0) // constructor
        : first(f), cur(f) { }

        virtual ~Progression() { }; // destructor
        void printProgression(int n); // print the first n values
        virtual long firstValue(); // reset
        virtual long nextValue(); // advance
    protected:
        long first; // first value
        long cur; // current value
};

long Progression::firstValue() { // reset
    cur = first;
    return cur;
}

long Progression::nextValue() {
    return cur++;
}

void Progression::printProgression(int n) { // print n values
    std::cout << firstValue(); // print the first
    for (int i = 2; i <= n; i++) // print 2 through n
        std::cout << " " << nextValue();
    std::cout << std::endl;
}

class AbsProgression : public Progression
{
private:
    long prev;
    long second;
public:
    AbsProgression() : Progression(2), second(200), prev(second + first) {}
    AbsProgression(long f, long s) : Progression(f), second(s), prev(s + f) {}

    virtual long firstValue()
    {
        cur = first;
        prev = second + first;
        return cur;
    }

    virtual long nextValue()
    {
        long temp = prev;
        prev = cur;
        cur = std::abs(cur - temp);
        return cur;
    }
};

int main(int argc, char const *argv[])
{
    AbsProgression defaultProgression, anotherProgression(2, 20);

    defaultProgression.printProgression(10);
    anotherProgression.printProgression(10);

    return 0;
}
