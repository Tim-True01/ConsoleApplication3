#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex();
    Complex(double r, double i);
    Complex(const Complex& other);
    ~Complex();
    void Show() const;
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    Complex& operator=(const Complex& other);
    Complex& operator+=(const Complex& other);

    Complex& operator++();
    Complex operator++(int);

    Complex& operator--();
    Complex operator--(int);
    bool operator>(const Complex& other) const;
    bool operator<(const Complex& other) const;
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    friend ostream& operator<<(ostream& out, const Complex& number);
    friend istream& operator>>(istream& in, Complex& number);
};

#endif
