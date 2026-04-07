#include <iostream>

class Fixed {
	
private:
	int _fixp; //fixpoint = the Raw bits = the raw integer value (not 5 but 1280)
	static const int _bits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& src); // Copy constructor

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	Fixed& operator=(const Fixed& src);

};


/*
A Copy Constructor is called/is useful
	- when one object initialiazes another object
	- when an object is returned by value from a function
	- object is passed by value to a function 

Typical usecase: When a Deep Copy of the object is requiered
	- this is necesary if the object has dynamically allocated memry

The Default Copy constructer creates a shallow copy of the original object
	- so if an objects stores a *p (heap), the shallow copy whill inheret that exact pointer
	- the *p will point to the same value in memory
	- if you change the *p value of the original, you change the value within the copy as well
		Number Ori(10); // *p will be set to hold the value 10
		Number Cpy = Ori;
		*(Ori.p) = 20; // then Cpy.pwill change from 8 to 20 aswell
	- problem occurs when the deconstructor frees the same memory location twice
*/



