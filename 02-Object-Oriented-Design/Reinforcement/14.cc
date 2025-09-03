/*
# R-2.14
Consider the following code fragment:
What is the output from calling the main function of the Maryland class?

*/
#include <iostream>
using namespace std;

class Object
{ public: virtual void printMe() = 0; };

class Place : public Object
{ public: virtual void printMe() { cout << "Buy it.\n"; } };

class Region : public Place
{ public: virtual void printMe() { cout << "Box it.\n"; } };

class State : public Region
{ public: virtual void printMe() { cout << "Ship it.\n"; } };

class Maryland : public State
{ public: virtual void printMe() { cout << "Read it.\n"; } };

int main() {
    Region* mid = new State;
    State* md = new Maryland;
    Object* obj = new Place;
    Place* usa = new Region;

    md->printMe();      // Read  it.
    mid->printMe();     // Ship it.
    
    (dynamic_cast<Place*>(obj))->printMe(); // Buy it.
    obj = md;
    (dynamic_cast<Maryland*>(obj))->printMe(); // Read it.
    obj = usa;
    (dynamic_cast<Place*>(obj))->printMe(); // Box it.      
    usa = md;
    (dynamic_cast<Place*>(usa))->printMe(); // Read it.      
    return EXIT_SUCCESS;
}