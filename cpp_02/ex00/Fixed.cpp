#include "Fixed.hpp"

//Def Cons
//Cpy Cons
//Des
//Copy assignment operator
//getter & setter

Fixed::Fixed(): _fixp(0){
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src){
	std::cout << "Copy Constructor called" << std::endl;
	this->_fixp = src._fixp;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
};

//Check addresses is good practice for later, when you have to delete existing *ptr memory to assign new one, otherwise deletion of own data possible
Fixed& Fixed::operator=(const Fixed& src){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src){
        this->_fixp = src._fixp;
    }
	return *this;
}

int Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return _fixp;
}

void Fixed::setRawBits( int const raw ){
	//std::cout << "setRawBits member function called" << std::endl;
	_fixp= raw;
}



/*Returning a reference from the Assignment operator=  is the standard practice 
in C++ because it allows for operator chaining and avoids unnecessary overhead.
Eg: a = b = c;

	1.	b = c is executed first.
	2.	a = b is executed secondly
	!	if b = c does return (void) a has nothing to assign itself to: a = void(b=c)
	-> If your operator returned void, the code a = b = c; would result in a compilation error because a would be trying to assign itself to "nothing."

Also: Efficiency!
	-> If you returned by value (Fixed instead of Fixed&), the compiler would have to:
	1.	Create a temp cpy of the object that was returned == Call Copy Construtor for temp(b) and do a = temp;
	!	In C++, temporary objects (also called rvalues) are short-lived. Their "life" is strictly defined
		- Born: At the return statement
		- Used: In the expression that called the function (a = b = c)
		- Destroyed at semicolon
	2. The line of code ends at the semicolon ;
*/


/*
A fixed-point number is a way to represent real (fractional) numbers using integers with an implied fixed position for the decimal (binary) point.
*/
