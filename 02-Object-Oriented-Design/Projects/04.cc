/*
# P-2.4
Write a simulator as in the previous project, but add a Boolean gender
field and a floating-point strength field to each Animal object. Now, if
two animals of the same type try to collide, then they only create a new
instance of that type of animal if they are of different genders. Otherwise,
if two animals of the same type and gender try to collide, then only the
one of larger strength survives.
*/
#include <iostream>

class Animal
{
private:
    bool gender;
    float strength;
public:
    Animal(const float _strength = 3.14, const bool _gender = true) : strength(_strength), gender(_gender) {}
    Animal collide(Animal& other)
    {
        if (gender != other.gender)
        {
            return Animal((strength + other.strength) / 2 + rand() % 10, rand() % 1);
        }

        if (strength > other.strength)
        {
            other.strength = 0.0f;
            return *this;
        }
        else
        {
            strength = 0.0f;
            return other;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Animal &a)
    {
        os << a.strength << " gender:" << a.gender << "\n";
        
        return os;
    }
};

int main(int argc, char const *argv[])
{
    Animal a1, a2(6.18, false), a3(3.18, true);

    std::cout << a1 << a2 << a3 << a1.collide(a2) << a1.collide(a3) << a1;
    return 0;
}

