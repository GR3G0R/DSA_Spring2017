//  FILE: Complex.h
//  CLASS PROVIDED: Complex (part of namespace delpe_complex_h)
//  CONSTRUCTOR for the Complex class:
//    Complex(const double r, const double i)
//    Postcondition: complex number set is set with (m_real, m_imaginary)
//
//  CONSTANT MEMBER FUNCTIONS for Complex class:
//    double getReal() const
//    Postcondition: The value returned is the real component of the complex number
//
//    double getImaginary() cont
//    Postcondition: The value returned is the imaginary componenet of the complex number
//
//  MEMBER FUNCTIONS for Complex class
//    void printComplex() const;
//    Postcondition: Complex number written to screen
//
//    void setReal(const double)
//    Postcondition: m_real initialized
//
//    void setImaginary(const double)
//    Postcondition: m_imaginary initialized
//
//    Complex& operator+=(const Complex a)
//    Postcondition: a has been added to Complex object
//
//    Complex& operator-=(const Complex a)
//    Postcondtion: a has been subtracted from Complex object
//
//  NONMEMBER FUNCTIONS for the Complex class
//    Comlex operator+(const Complex a, const Complex b)
//    Postcondition: Complex number returned must be union of complex a and complex b
//
//    Complex operator*(const Complex a, const Complex b)
//    Postcondtion: returns a x b
//
//    Complex operator/(const Complex a, const Complex b)
//    Postcondtion: returns a / b
//
//    Complex operator-(const Complex a, const Complex b)
//    Postcondition: Complex number returned must be difference of Complex a and Complex b
//
//    bool operator==(const Complex a, const Complex b)
//    Postcondtion: the return value is true if a is identical to b
//
//    bool operator!=(const Complex a, cost Complex b)
//    Postcondtion: the return value is true if a is not identical to b
//
//    std::ostream& operator<<(std::ostream& o, const Complex& c)
//    Postcondition: the sequence of characters in source have been written to o.
//    the return value is ostream o.
//
//    std::ostream& operator>>(std::istream& is, Complex& c)
//    Postcondition: a string has been read from the instream is and the is stream is is then
//    returned by the function.
//
//    void complexAdd(Complex, Complex)
//    Postcondition: Complex number returned must be union of complex a and complex b
//
//    void complexSub(Complex, Complex);
//    Postcondition: Complex number returned must be difference of Complex a and Complex b
//
//  VALUE SEMANTICS for the Complex class:
//    Assignments and the copy consturctor may be used with Complex class
//
//  REASON FOR OMITTING DEFAULT CONSTRUCTOR: In this example we want to deter the user from
//  initializing our calss without providing valid data. We want to establish explicit prevention
//  of potential instances of our class being created without valid user input.

#ifndef DELPE_COMPLEX_H
#define DELPE_COMPLEX_H

namespace delpe_complex_h {

    class Complex{
         private:
            double m_real;
            double m_imaginary;
        public:

            Complex (const double r, const double i);

            double getReal() const;
            double getImaginary() const;

            void setReal(const double);
            void setImaginary(const double);

            void printComplex() const;

            Complex& operator+=(const Complex);
            Complex& operator-=(const Complex);

            friend std::ostream& operator<<(std::ostream&, const Complex&);
    };

    std::ostream& operator<<(std::ostream&, const Complex&);
    std::istream& operator>>(std::istream&, Complex&);

    Complex operator+(const Complex, const Complex);
    Complex operator*(const Complex, const Complex);
    Complex operator/(const Complex, const Complex);
    Complex operator-(const Complex, const Complex);

    bool operator==(const Complex, const Complex);
    bool operator!=(const Complex, const Complex);

    void complexAdd(Complex, Complex);
    void complexSub(Complex, Complex);
}

#endif
