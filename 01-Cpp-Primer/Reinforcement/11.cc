/*
# R-1.11 
Write a C++ class, Flower, that has three member variables of type string,
int, and float, which respectively represent the name of the flower, its
number of pedals, and price. Your class must include a constructor method
that initializes each variable to an appropriate value, and your class should
include functions for setting the value of each type, and getting the value
of each type.
*/
#include <iostream>
#include <string>
using std::string;

class Flower {
public:
    // constructor
    Flower(string _name, int _petals, float _price) : name(_name), petals(_petals), price(_price) {}

    // getters
    string getName() const {
        return this->name;
    }

    int getPetals() const {
        return this->petals;
    }

    float getPrice() const {
        return this->price;
    }

    // setters
    void setName(string _name) {
        this->name = _name;
    }

    void setPetals(int _petals) {
        this->petals = _petals;
    }

    void setPrice(float _price) {
        this->price = _price;
    }

private: 
    string name;
    int petals;
    float price;
};

int main(const int argc, const char** argv)
{
    Flower iris("Iris", 3, 100.00f);

    std::cout << "Name: " << iris.getName() << " \nPetals: " << iris.getPetals() << " \nPrice: " << iris.getPrice() << "Rs\n\n";

    iris.setName("Iris Virginia");
    iris.setPetals(4);
    iris.setPrice(240.0f);

    std::cout << "Name: " << iris.getName() << " \nPetals: " << iris.getPetals() << " \nPrice: " << iris.getPrice() << "Rs\n\n";
    return (0);
}
