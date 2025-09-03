/*
# R-2.8
Give a short fragment of C++ code that uses the progression classes from
Section 2.2.3 to find the 7th value of a Fibonacci progression that starts
with 3 and 4 as its first two values.
*/

#include <iostream>

class Progression { // a generic progression
    public:
        Progression(long f = 0) // constructor
        : first(f), cur(f) { }

        virtual ~Progression() { }; // destructor
        void printProgression(int n); // print the first n values
    protected:
        virtual long firstValue() = 0; // reset
        virtual long nextValue() = 0; // advance
    protected:
        long first; // first value
        long cur; // current value
};

void Progression::printProgression(int n) { // print n values
    std::cout << firstValue(); // print the first
    for (int i = 2; i <= n; i++) // print 2 through n
        std::cout << " " << nextValue();
    std::cout << std::endl;
}

class FibonacciProgression : public Progression { // Fibonacci progression
    public:
        FibonacciProgression(long f = 0, long s = 1); // constructor
    protected:
        virtual long firstValue(); // reset
        virtual long nextValue(); // advance
    protected:
        long second; // second value
        long prev; // previous value
};

FibonacciProgression::FibonacciProgression(long f, long s)
: Progression(f), second(s), prev(second - first) { }

long FibonacciProgression::firstValue() { // reset
    cur = first;
    prev = second - first; // create fictitious prev
    return cur;
}

long FibonacciProgression::nextValue() { // advance
    long temp = prev;
    prev = cur;
    cur += temp;
    return cur;
}

int main(int argc, char const *argv[])
{
    FibonacciProgression fp(3l, 4l);

    fp.printProgression(7);

    return 0;
}

