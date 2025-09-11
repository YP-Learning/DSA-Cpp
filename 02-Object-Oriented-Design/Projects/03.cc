/*
# P-2.3
Implement a templated C++ class Vector that manipulates a numeric vector. 
Your class should be templated with any numerical scalar type T,
which supports the operations + (addition), − (subtraction), and * (multiplication). 
In addition, type T should have constructors T(0), which
produces the additive identity element (typically 0) and T(1), which 
produces the multiplicative identity (typically 1). Your class should provide a
constructor, which is given the size of the vector as an argument. It should
provide member functions (or operators) for vector addition, vector subtraction, 
multiplication of a scalar and a vector, and vector dot product.
Write a class Complex that implements a complex number by overloading 
the operators for addition, subtraction, and multiplication. Implement
three concrete instances of your class Vector with the scalar types int,
double, and Complex, respectively.
*/
#include <iostream>
#include <cstring>

class Complex
{
private:
    double real, imag;
public:
    Complex(double val = 0) : real(val), imag(val) {}
    Complex(double _real, double _imag) : real(_real), imag(_imag) {}

    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex &other) const
    {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex &other) const
    {
        return Complex(real * other.real, imag * other.imag);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex &cx)
    {
        os << cx.real << "+" << cx.imag << "i";
        
        return os;
    }
};

template<typename T>
class Vector
{
private:
    T *data;
    size_t size;
public:
    Vector(size_t _size) : size(_size)
    {
        data = new T[_size];
    }

    Vector(size_t _size, T elem) : size(_size)
    {
        data = new T[_size];

        for (size_t i = 0; i < size; i++)
            data[i] = elem;
    }

    Vector(std::initializer_list<T> init_list) : size(init_list.size())
    {
        data = new T[size];
        std::copy(init_list.begin(), init_list.end(), data);
    }

    Vector<T> operator+(const Vector<T> &other) const
    {
        if (size != other.size) 
            throw std::runtime_error("Sizies of vector do not match");

        Vector<T> blank(size);

        for (size_t i = 0; i < size; i++)
        {
            blank.data[i] = data[i] + other.data[i];
        }

        return blank;
    }

    Vector<T> operator-(const Vector<T> &other) const
    {
        if (size != other.size) 
            throw std::runtime_error("Sizies of vector do not match");

        Vector<T> blank(size);

        for (size_t i = 0; i < size; i++)
        {
            blank.data[i] = data[i] - other.data[i];
        }

        return blank;
    }

    Vector<T> operator*(const Vector<T> &other) const
    {
        if (size != other.size) 
            throw std::runtime_error("Sizies of vector do not match");

        Vector<T> blank(size);

        for (size_t i = 0; i < size; i++)
        {
            blank.data[i] = data[i] * other.data[i];
        }

        return blank;
    }

    T dot(const Vector<T> &other) const
    {
        if (size != other.size) 
            throw std::runtime_error("Sizies of vector do not match");

        T sum(0);

        for (size_t i = 0; i < size; i++)
        {
            sum = sum + data[i] * other.data[i];
        }

        return sum;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector<T> &vec)
    {
        for (size_t i = 0; i < vec.size; i++)
        {
            os << vec.data[i] << " ";
        }
        
        return os;
    }
};


int main(int argc, char const *argv[])
{
    Vector<int> vi1(4);
    Vector<int> vi3(4, 1);
    Vector<int> vi2({ 1, 2, 3, 4 });
    Vector<double> vd1(3, 2.12), vd2({ 3.14, 6.19, 1.18 });
    Vector<Complex> vc1(3, 1), vc2({Complex(1, 2), Complex(2, 3), Complex(3, 4)});

    std::cout << vi1 << "\n" << vi2 << "\n" << vi3 << "\n";
    std::cout << "Addition : " << vi2 + vi3 << "\nsubtraction: " << vi2 - vi3 << "\nmultiplication: " << vi2 * vi3 << "\ndot: " << vi2.dot(vi3) << "\n\n";

    std::cout << vd1 << "\n" << vd2 << "\n";
    std::cout << "Addition : " << vd1 + vd2 << "\nsubtraction: " << vd2 - vd1 << "\nmultiplication: " << vd1 * vd2 << "\ndot: " << vd2.dot(vd1) << "\n\n";

    std::cout << vc1 << "\n" << vc2 << "\n";
    std::cout << "Addition : " << vc1 + vc2 << "\nsubtraction: " << vc2 - vc1 << "\nmultiplication: " << vc1 * vc2 << "\ndot: " << vc2.dot(vc1) << "\n\n";

    return 0;
}

