/*
# R-2.9
If we choose inc = 128, how many calls to the nextValue function from
the ArithProgression class of Section 2.2.3 can we make before we cause
a long-integer overflow, assuming a 64-bit long integer?
*/

#include <iostream>
#include <climits>

class Progression { // a generic progression
    public:
        Progression(long f = 0) // constructor
        : first(f), cur(f) { }

        virtual ~Progression() { }; // destructor
        void printProgression(int n); // print the first n values
        virtual long firstValue(); // reset
        virtual long nextValue() = 0; // advance
    protected:
        long first; // first value
        long cur; // current value
};

long Progression::firstValue() { // reset
    cur = first;
    return cur;
}

void Progression::printProgression(int n) { // print n values
    std::cout << firstValue(); // print the first
    for (int i = 2; i <= n; i++) // print 2 through n
        std::cout << " " << nextValue();
    std::cout << std::endl;
}

class ArithProgression : public Progression { // arithmetic progression
    public:
        ArithProgression(long i = 1); // constructor
        virtual long nextValue(); // advance
    protected:
        long inc; // increment
};

ArithProgression::ArithProgression(long i) // constructor
: Progression(), inc(i) { }

long ArithProgression::nextValue() { // advance by adding
    cur += inc;
    return cur;
}

int main(int argc, char const *argv[])
{
    // ArithProgression ap(128);

    // long curr, prev;
    // long counter = 0;

    // curr = ap.firstValue();
    // std::cout << curr << "\n";

    // do {
    //     prev = curr;
    //     curr = ap.nextValue();
    //     std::cout << curr << "\n";
    //     counter++;
    // } while (prev < curr);

    // std::cout << "Calls to NextValue: " << counter << std::endl;
    std::cout << LONG_MAX << std::endl;
    std::cout << LONG_MAX / 128L << std::endl; 

    return 0;
}

