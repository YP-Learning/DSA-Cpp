/*
# C-2.6
Write a C++ class that is derived from the Progression class to produce
a progression where each value is the square root of the previous value.
(Note that you can no longer represent each value with an integer.) You
should include a default constructor that starts with 65,536 as the first
value and a parametric constructor that starts with a specified (double)
number as the first value
*/
#include <iostream>
#include <cmath>

class Progression { // a generic progression
    public:
        Progression(double f = 0) // constructor
        : first(f), cur(f) { }

        virtual ~Progression() { }; // destructor
        void printProgression(int n); // print the first n values
        virtual double firstValue(); // reset
        virtual double nextValue(); // advance
    protected:
        double first; // first value
        double cur; // current value
};

double Progression::firstValue() { // reset
    cur = first;
    return cur;
}

double Progression::nextValue() {
    return cur++;
}

void Progression::printProgression(int n) { // print n values
    std::cout << firstValue(); // print the first
    for (int i = 2; i <= n; i++) // print 2 through n
        std::cout << " " << nextValue();
    std::cout << std::endl;
}

class SqrtProgression : public Progression
{
public:
    SqrtProgression(double f = 65536) : Progression(f) {}
    virtual double nextValue() {
        cur = std::sqrt(cur);
        return cur;
    }
};

int main(int argc, char const *argv[])
{
    SqrtProgression dp, sp(1L<<32);

    dp.printProgression(10);
    sp.printProgression(10);

    return 0;
}

