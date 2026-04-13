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
	float	toFloat( void ) const;		//new
	int toInt( void ) const;			//new
	Fixed& operator=(const Fixed& src);	//new

};

std::ostream& operator<<(std::ostream &out,const Fixed &fixed); //overload of insertion operator


/*
Overloading Operators 
										LEFT SIDE					RIGHT SIDE
RULE: return_type operator??(object calling the functinon, Parameter passed to the function)

-> The object on the left of the operator is the one "calling" the function.

1. Overloading as a Member Function 
	-> left side implicit -> pass only right parameter
	- When define operator inside a class, the object on the left of the operator is the one "calling" the function.
	== the "left side" is implicit. == t it passed as this to the function, so you only need to pass the parameter in the right
	E.g: Fixed& operator=(const Fixed& src)

2. Overloading as a Non-Member Function -> need to pass two paramteres
	Example: Overloading cout << MyClass
	!-->> std::cout is a std::ostream
	- You can't go into the official C++ library and add a member function to ostream
	- So you define a non-Member Function with left << right
	Template: returntype(of leftside) operator<<(leftside,rightside);
	--> std::ostream& operater<<(std::ostream& out, MyClass )
*/



//If you setRawBits(1280), you set the FixedPoint value to 1280
//If you call getRawBits(), you are asking for the raw, unscaled integer (1280).

/*

Floating Point is Scientific Notation in base 2
IEEE 754 Standard Single Precision (32 bits)


So all it can do is:	-Store 23 Significant Digits (Mantissa)
			-decide where the decimal Point in those is
			-multiply the Mantissa with 2^x (Exponent Box)
			 (x range from decimal -126 to +127)

This means: Large and Small Numbes can be stored because of the Exponent Box
But Precision is lost because:
	- only 23 Significant Binary Digits
	- Scientific Notation can not Represent Recurring Numbers like 1/3
Also:
       -> Two Exponents are reserved for special cases
	Represent 0 
	- is impossible if the mantissa is always betwenn 1 and almost 2. 
	- If the Exponent is 0 (127 in b2), the number is now 
	  interpreted as subnormal with a leading 0 in the Mantissa
	  instead of 1. This allows representation of very small
	  values and zero.
	-
	Representing Infinity or Overflow
	- Is done with Exponent 127 (255 in b2)

Exponent Box (0-255) so with 127 bias; Range should be from -127 to 128.
But it is actually from -126 to 127 because two Exponents are Reserved


Actual Exponent Range for Normalized Numbers 
				Binary  |  Decimal (-127)		
Minimum Exponent (00000001):  	   1    |   -126 
Maximum Exponent (11111110):      254	|    127
Special Exponent (00000000): 	   0	|   -127
Infinity/NaN     (11111111): 	   255  |    128



1. Why pass by Value (float const f)?
In C++, we usually pass large objects (like strings or classes) by reference 
to avoid expensive copying. However, for "primitive" types like int, char, and float:

- Size: A float is small (usually 32 bits). A reference is technically a pointer under 
the hood, which is also 32 or 64 bits. Passing a reference doesn't save any memory or time.

- Performance: Accessing a value directly is often faster 
for the CPU than following a reference (memory address) to find the value.

- Convention: It is standard practice in C++ to pass basic numeric types by value.
*/


