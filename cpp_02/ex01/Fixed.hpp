#include <iostream>
#include <cmath>

class Fixed {
	
private:
	int _fixp; 					//fixpoint = the Raw bits = the raw integer value (not 5 but 1280)
	static const int _bits = 8; 

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& src); 		// Copy constructor
	Fixed(const int n); 			//Const Integer Constructor, converts n to _fixp
	Fixed(const float f);			//Const float Constructor, converts f to _fixp
	
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int toInt( void ) const;
	Fixed& operator=(const Fixed& src);

};

std::ostream& operator<<(std::ostream &out,const Fixed &fixed);

//Why return out it if they already have it?
//They need it because of Chaining: std::cout << a << b
// 1. (std::cout << a) runs. 
// 2. It returns std::cout.
// 3. The expression now looks like: (The returned std::cout) << b;
// 4. Now the second << can run because it has a stream on its left side.

/*
1. Overloading as a Member Function
	If you define operator+ inside your class, the "left side" is implicit. 
	It is the object itself (this).
	Left side: The object the function belongs to (the this pointer).
	Right side: The single parameter passed in the brackets.
	like
	Fixed& operator=(const Fixed& src)

2. Overloading as a Non-Member Function
	std::cout is a std::ostream
	You can't go into the official C++ library and add a member function to ostream
	So if zou want to e.g. std::cout << MyClass
	So you define a non-Member Function with left << right
		returntype operator<<(leftside,rightside);
		std::ostream& operater<<(std::ostream& out, MyClass )
*/



//If you setRawBits(1280), you set the FixedPoint value to 1280
//If you call getRawBits(), you are asking for the raw, unscaled integer (1280).

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



1. Why pass by Value (float const f)?
In C++, we usually pass large objects (like strings or classes) by reference 
to avoid expensive copying. However, for "primitive" types like int, char, and float:

- Size: A float is small (usually 32 bits). A reference is technically a pointer under 
the hood, which is also 32 or 64 bits. Passing a reference doesn't save any memory or time.

- Performance: Accessing a value directly is often faster 
for the CPU than following a reference (memory address) to find the value.

- Convention: It is standard practice in C++ to pass basic numeric types by value.
*/


