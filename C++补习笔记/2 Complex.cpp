#include "Complex.h"
#include<iomanip>
Complex::Complex() { re = 0; im = 0; }
Complex::Complex(double x) { re = x; im = 0; }
Complex::Complex(double x, double y) { re = x; im = y; }
Complex::~Complex() {}
Complex& Complex::operator=(Complex b) { re = b.re; im = b.im; return *this; }
Complex Complex::operator+(Complex &b) { return Complex(re + b.re, im + b.im); }
Complex Complex::operator-(Complex &b) { return Complex(re - b.re, im - b.im); }
Complex Complex::operator*(Complex &b) 
{ return Complex(re * b.re-im * b.im, re * b.im + im * b.re); }
Complex Complex::operator/(Complex &b) 
{ 
	double t = b.re * b.re + b.im * b.im;
	return Complex((re*b.re+im*b.im)/t,(b.re*im-b.im*re)/t); 
}
ostream & operator<<(ostream &os, Complex b)
{
	os << fixed << setprecision(2) << b.re << ' ' << b.im << endl;
	return os;
}