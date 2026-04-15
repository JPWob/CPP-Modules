#include <iostream>

class Fixed {
	
private:
	int _fixp; 							//fixpoint = the Raw bits = the raw integer value (not 5 but 1280)
	static const int _bits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& src); 			// Copy constructor
	Fixed& operator=(const Fixed& src);	//Assignment Operator

	int getRawBits( void ) const;
	void setRawBits( int const raw );

};


/*
“Orthodox Canonical Form” (OCF) in C++ is a standard way of defining a class 
so it behaves correctly with copying, assignment, and destruction.

In C++, if you don’t explicitly define a copy constructor, 
the compiler generates a default copy constructor for you.
The default copy constructor performs a member-wise (shallow) copy of the object.
For primitive types (int, char) this is fine.
But for pointer members, it copies the pointer value, not what it points to. (shallow, no copy made)
*/

/*
Copy constructor = construct a brand new object == should initialize
Copy assignment = replace an already existing object == should replace

They solve similar problems, but they happen in different object states, 
so their mechanics are not interchangeable.

*/




