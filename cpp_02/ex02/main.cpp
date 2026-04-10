#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& out,const Fixed& fixed){
	out << fixed.toFloat();
	return out;
}

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

/*
The Big Picture: Why this class is "Canonical"
By completing these functions, you have finished what is known as an Orthodox Canonical Class. This means your class behaves exactly like a built-in type (like int or float).

- It can be copied 		and assigned safely.
- It can be compared 	using standard math symbols.
- It can be used 		in arithmetic expressions.
- It can be passed 		to std::cout for printing.
- It can be compared via utility functions like min and max.

*/
