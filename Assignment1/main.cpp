//  FILE: main.cpp

#include <iostream>  //Facilitate access to input and output stream
#include "complex.h"  //Include header file
using namespace std;
using delpe_complex_h::Complex;  //Access delpe_complex_h namespace

int main()
{
    //Declare Complex and Input Variables:
    Complex c1(2.0,4.0), c2(3.0,5.0), result1(0.0,0.0), input(0.0,0.0), result2(0.0,0.0), result3(0.0,0.0), result4(0.0,0.0), result5(0.0,0.0);
    Complex result_mult(0.0,0.0), result_div(0.0,0.0), result_sub_combo(0.0,0.0), result_add_combo(0.0,0.0), result_eq(0.0,0.0);
    double op1, op2, op3, op4;

    //User Interface:
    cout << "Input real component of first complex number: ";
    cin >> op1;
    cout << "Inpute imaginary component of first complex number: ";
    cin >> op2;
    cout << "Input real component of second complex number: ";
    cin >> op3;
    cout << "Inpute imaginary component of second complex number: ";
    cin >> op4;

    Complex c_op1(op1,op2);  //Create complex object passing user input as real and complex parameters
    Complex c_op2(op3,op4);  //Create complex object passing user input as real and complex parameters
    result1 = c1 + c2;  //Add two complex numbers
    result2 = c1 - c2;  //Subtract two complex numbers
    result3 = c_op1 + c_op2;  //Add two complex numbers created with user input
    result4 = (c_op1 + c_op2) - result3;  //Expression of addition and subtraction of complex numbers
    result_mult = c_op1 * c_op2;  //Multiply two complex numbers
    result_div = c_op1 / c_op2;  //Division of two complex numbers
    result_sub_combo = c_op1 -= c_op2;  //Demonstrate combined assignment operator functionality
    result_add_combo = c_op1 += c_op2;  //Demonstrate combined assignment operator functionality

    //Write Operation Results to Screen:
    cout << "Sum: "; complexAdd(c_op1,c_op2); cout << endl;
    cout << "Differance: "; complexSub(c_op1, c_op2); cout << endl;
    cout << "Complex#1 * Complex#2: " << result_mult << endl;
    cout << "Complex#1 / Complex#2: " << result_div << endl;
    cout << "Complex#1 += Complex#2: " << result_add_combo << endl;
    cout << "Complex#1 -= Complex#2: " << result_sub_combo << endl;
    cout << "Result1 == Result2: " << (result1 == result2) << endl;
    cout << "R1: " << result1 << endl;
    cout << "R2: " << result2 << endl;
    cout << "R3: " << result3 << endl;
    cout << "R4: " << result4 << endl;


}

