/*
# C-2.9
Write a C++ program that can input any polynomial in standard algebraic
notation and outputs the first derivative of that polynomial.
*/
#include <iostream>
#include <vector>
#include <string>

// 3x^3 - 2x + 1
// 3, 0, -2, 1 - 3
class Polynomial
{
private: 
    std::vector<float> coeff;
public:
    Polynomial(std::vector<float> _coeff) : coeff(_coeff) {}
    Polynomial derivative()
    {
        std::vector<float> newCoefs = {};
        for (int i = coeff.size() - 1; i > 0; i--)
        {
            newCoefs.push_back(coeff[coeff.size() - i - 1] * (i));
        }

        return Polynomial(newCoefs);
    }

    friend std::ostream& operator<<(std::ostream& os, Polynomial &p)
    {
        for (int i = p.coeff.size() - 1; i > 0; i--)
        {
            if (p.coeff[p.coeff.size() - i - 1] == 0)
                continue;

            os << p.coeff[p.coeff.size() - i - 1] << "x^" << i << " + ";
        }

        if (p.coeff[p.coeff.size() - 1] != 0)
            os << p.coeff[p.coeff.size() - 1];

        return os;
    }
};

int main(int argc, char const *argv[])
{
    Polynomial p({3, 0, -2, 1});
    Polynomial dxp = p.derivative();

    std::cout << p << "\n" << dxp << std::endl;

    return 0;
}

