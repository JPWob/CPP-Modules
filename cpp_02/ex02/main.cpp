#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "a:  "		<< std::endl << a << std::endl;
	std::cout << "++a:  "	<< std::endl << ++a << std::endl;
	std::cout << "a:  "		<< std::endl << a << std::endl;
	std::cout << "a++:  "	<< std::endl << a++ << std::endl;
	std::cout << "a: "		<< std::endl << a << std::endl;
	std::cout << "b: "		<< std::endl << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;


	//AI  Testcases
	std::cout << "--- Overflows & Large Values ---" << std::endl;
    Fixed large(500);
    Fixed small(0.01f);
    std::cout << "large: " << large << std::endl;
    std::cout << "small: " << small << std::endl;
    std::cout << "large * small: " << large * small << " (Expected ~5.0)" << std::endl;

    std::cout << "\n--- Chained Arithmetic ---" << std::endl;
    Fixed c = Fixed(2) + Fixed(3.5f) * Fixed(2);
    // (3.5 * 2) = 7; 7 + 2 = 9
    std::cout << "2 + 3.5 * 2 = " << c << std::endl;

    std::cout << "\n--- Comparison Operators ---" << std::endl;
    Fixed x(10);
    Fixed y(10.00390625f); // This is 10 + (1/256)
    
    std::cout << "x: " << x << " | y: " << y << std::endl;
    std::cout << "x < y: " << (x < y) << " (1)" << std::endl;
    std::cout << "x > y: " << (x > y) << " (0)" << std::endl;
    std::cout << "x == x: " << (x == x) << " (1)" << std::endl;
    std::cout << "x != y: " << (x != y) << " (1)" << std::endl;

    std::cout << "\n--- Division by zero / Small values ---" << std::endl;
    Fixed d1(10);
    Fixed d2(0.5f);
	//std::cout << "10 / 0 = " << d1 / 0 << " (Error Expected)" << std::endl;
    std::cout << "10 / 0.5 = " << d1 / d2 << " (Expected 20)" << std::endl;

    std::cout << "\n--- Min/Max Constants ---" << std::endl;
    const Fixed c1(42);
    const Fixed c2(24);
    std::cout << "Max(const 42, const 24): " << Fixed::max(c1, c2) << std::endl;
    std::cout << "Min(const 42, const 24): " << Fixed::min(c1, c2) << std::endl;

	return 0;
}

// 1:256 = 0.00390625

/*
The Big Picture: Why this class is "Canonical"
By completing these functions, you have finished what is known as an Orthodox Canonical Class. 
This means your class behaves exactly like a built-in type (like int or float).

- It can be copied 		and assigned safely.
- It can be compared 	using standard math symbols.
- It can be used 		in arithmetic expressions.
- It can be passed 		to std::cout for printing.
- It can be compared via utility functions like min and max.

*/
