//  FILE: Complex.cpp


#include <iostream>
#include <cassert>  //Facilitate access to assert
#include "complex.h"


namespace delpe_complex_h {

//Constructor
Complex::Complex(const double r, const double i): m_real(r), m_imaginary(i) {}

//Getter function returns value of m_real member variable
double Complex::getReal() const
{
    return m_real;
}

//Getter function returns value of m_imaginary member variable
double Complex::getImaginary() const
{
    return m_imaginary;
}

//Setter function assigns value to m_real member variable
void Complex::setReal(const double r)
{
    m_real = r;
}

//Setter function assigns value to m_imaginary member variable
void Complex::setImaginary(const double i)
{
    m_imaginary = i;
}

//Print complex number
void Complex::printComplex() const
{
    std::cout << m_real << '+' << m_imaginary << 'i';
}

//Overload comobined assignment operator
Complex& Complex::operator+=(const Complex a)
{
    m_real += a.m_real;
    m_imaginary += a.m_imaginary;

    return *this;
}

//Overload combined assignment operator
Complex& Complex::operator-=(const Complex a)
{
    m_real -= a.m_real;
    m_imaginary -= a.m_imaginary;

    return *this;
}

//Overload extraction operator
std::ostream& operator<<(std::ostream& o, const Complex& c)
{
    return o << c.getReal() << '+' << c.getImaginary() << 'i';
}

//Overload insertion operator
std::istream& operator>>(std::istream& is, Complex& c)
{
    char ch = 0;
    double r = 0.0;
    double i = 0.0;

    is >> ch >> r >> ch >> i >> ch >> ch;

    c.setReal(r);
    c.setImaginary(i);

    return is;
}

//Overload addition operator
Complex operator+(const Complex a, const Complex b)
{
    Complex ret(a.getReal() + b.getReal(), a.getImaginary() + b.getImaginary());
    return ret;
}

//Overload multiplication operator
Complex operator*(const Complex a, const Complex b)
{
    double c, d, e, f;

    c = a.getReal(); //b
    d = a.getImaginary(); //c
    e = b.getReal();  //d
    f = b.getImaginary();  //e

    Complex ret(c * e - d * f, d * e + d * f);

    return ret;
}

//Overload devision operator
Complex operator/(const Complex a, const Complex b)
{
    double c, d, e, f;

    c = a.getReal(); //b
    d = a.getImaginary(); //c
    e = b.getReal(); //d
    f = b.getImaginary(); //e

    assert(d || e);

    Complex ret((c * e + d * f) / ( e * e + f * f), (d * e - f * c) / (e * e + f * f));

    return ret;

}

//Overload subtraction operator
Complex operator-(const Complex a, const Complex b)
{
    Complex ret(a.getReal() - b.getReal(), a.getImaginary() - b.getImaginary());
    return ret;
}

//Overload equality operator
bool operator==(const Complex a, const Complex b)
{
    return (a.getReal() == b.getReal() && a.getImaginary() == b.getImaginary());
}

//Overload not equal operator
bool operator!=(const Complex a, const Complex b)
{
    return (a.getReal() != b.getReal() || a.getImaginary() != b.getImaginary());
}

//Addition function return sum of two complex numbers
void complexAdd(Complex comp1, Complex comp2)
{
    double r , i;
    r = comp1.getReal() + comp2.getReal();
    i = comp1.getImaginary() + comp2.getImaginary();
    Complex comp3(r,i);
    comp3.setReal(r);
    comp3.setImaginary(i);
    comp3.printComplex();
}

//Subtraction funtion returns difference between two complex numbers
void complexSub(Complex comp1, Complex comp2)
{
    double r , i;
    r = comp1.getReal() - comp2.getReal();
    i = comp1.getImaginary() - comp2.getImaginary();
    Complex comp3(r,i);
    comp3.setReal(r);
    comp3.setImaginary(i);
    comp3.printComplex();
}

}
