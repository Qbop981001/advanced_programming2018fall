#include<iostream>
using namespace std;
template<class T>
class Iterator
{
public:
	Iterator(T *p = NULL) { ptr = p; }
	Iterator(Iterator &b) { ptr = b.ptr; }

	Iterator& operator = (Iterator &b) {	 ptr = b.ptr;return *this; }
	Iterator &operator++() {  ptr = ptr + 1;  return *this; }
	Iterator operator++(int) {
		Iterator temp(*this);	 ++*this; 
		return temp;
	}
	Iterator &operator--() { ptr = ptr - 1; return *this; }
	Iterator operator--(int) { Iterator temp(*this);	--*this;	return temp; }
	Iterator operator+(size_t n)
	{	
		int i=0;
		for (i = 0; i < n; i++) {
			ptr = ptr + 1;
		}
		return *this;
	}
	Iterator operator-(size_t n)
	{
		int i = 0;
		for (i = 0; i < n; i++) {
			ptr = ptr - 1;
		}
		return *this;
	}
	bool operator==(Iterator &b) { return (ptr == b.ptr); }
	bool operator!=(Iterator &b) {	return (ptr != b.ptr); }
	T& operator*() { return *ptr; }
	T *ptr;
};
