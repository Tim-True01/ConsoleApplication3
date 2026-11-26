#include "file.h"

Complex::Complex() {
    real = 0;
    imaginary = 0;
}
Complex::Complex(double r, double i) {
    real = r;
    imaginary = i;
}
Complex::Complex(const Complex& other) {
    real = other.real;
    imaginary = other.imaginary;
}
Complex::~Complex() {
}
void Complex::Show() const {
    cout << *this << endl;
}
Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real,
        imaginary + other.imaginary);
}
Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real,
        imaginary - other.imaginary);
}
Complex Complex::operator*(const Complex& other) const {
    return Complex(
        real * other.real - imaginary * other.imaginary,
        real * other.imaginary + imaginary * other.real
    );
}
Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real +
        other.imaginary * other.imaginary;

    if (denominator == 0) {
        throw runtime_error("Деление на ноль, ну так нельзя!");
    }

    return Complex(
        (real * other.real + imaginary * other.imaginary) / denominator,
        (imaginary * other.real - real * other.imaginary) / denominator
    );
}
Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        real = other.real;
        imaginary = other.imaginary;
    }

    return *this;
}
Complex& Complex::operator+=(const Complex& other) {
    real += other.real;
    imaginary += other.imaginary;

    return *this;
}
Complex& Complex::operator++() {
    real++;
    return *this;
}
Complex Complex::operator++(int) {
    Complex temp(*this);
    real++;
    return temp;
}
Complex& Complex::operator--() {
    real--;
    return *this;
}
Complex Complex::operator--(int) {
    Complex temp(*this);
    real--;
    return temp;
}


bool Complex::operator>(const Complex& other) const {
    double first = real * real + imaginary * imaginary;
    double second = other.real * other.real +
        other.imaginary * other.imaginary;

    return first > second;
}

bool Complex::operator<(const Complex& other) const {
    double first = real * real + imaginary * imaginary;
    double second = other.real * other.real +
        other.imaginary * other.imaginary;

    return first < second;
}

bool Complex::operator==(const Complex& other) const {
    double first = real * real + imaginary * imaginary;
    double second = other.real * other.real +
        other.imaginary * other.imaginary;
    return fabs(first - second) < 0.000000001;
}
bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& out, const Complex& number) {
    out << number.real;

    if (number.imaginary >= 0) {
        out << " + " << number.imaginary << "*i";
    }
    else {
        out << " - " << -number.imaginary << "*i";
    }

    return out;
}
istream& operator>>(istream& in, Complex& number) {
    cout << "Введите действительную часть: ";
    in >> number.real;

    cout << "Введите мнимую часть: ";
    in >> number.imaginary;
    return in;
}