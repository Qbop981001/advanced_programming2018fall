#include<iostream>
using namespace std;
class Complex {
private:
	double re; 
	double im; 
public:
	Complex();
	Complex(double x);
	Complex(double x, double y);
	~Complex();	
	Complex &operator= (Complex b);	
	Complex operator+ (Complex &b);		
	Complex operator- (Complex &b);		
	Complex operator* (Complex &b);		
	Complex operator/ (Complex &b);		
	friend ostream & operator<<(ostream &os, Complex b);	
};
