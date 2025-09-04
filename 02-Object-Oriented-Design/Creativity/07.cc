/*
# C-2.7
Write a program that consists of three classes, A, B, and C, such that B is a
subclass of A and C is a subclass of B. Each class should define a member
variable named “x” (that is, each has its own variable named x). Describe
a way for a member function in C to access and set A’s version of x to a
given value, without changing B or C’s version.
*/
#include <iostream>

class A
{
protected: 
    int x;
public: 
    A(int _x = 7) : x(_x) {}
    virtual void print() const
    {
        std::cout << "A::x = " << x << "\n";
    }
};

class B : public A
{
protected: 
    int x;
public: 
    B(int _x = 12) : x(_x) {}
    virtual void print() const
    {
        A::print();
        std::cout << "B::x = " << x << "\n";
    }
};

class C : public B
{
protected: 
    int x;
public: 
    C(int _x = 17) : x(_x) {}
    virtual void print() const
    {
        B::print();
        std::cout << "C::x = " << x << "\n";
    }

    void set(int ax = 8, int bx = 18, int cx = 28)
    {
        A::x = ax;
        B::x = bx;
        C::x = cx;
    }
};

int main(int argc, char const *argv[])
{
    C c;
    c.print();

    c.set(2, 22, 222);
    c.print();

    return 0;
}

